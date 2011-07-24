/* File: ast_decl.cc
 * -----------------
 * Implementation of Decl node classes.
 */
#include "ast_decl.h"
#include "ast_type.h"
#include "ast_stmt.h"

Decl::Decl(Identifier *n) : Node(*n->GetLocation()), scope(new Scope) {
    Assert(n != NULL);
    (id=n)->SetParent(this);
}

bool Decl::operator==(const Decl &rhs) {
    return *id == *rhs.id;
}

int Decl::Check(List<Scope*> *scopeList, List<Type*> *typeList) {
    /* TODO: Once all subclasses support this function it should be made a pure
     * virtual function.
     */
    return 0;
}

void Decl::BuildScope(Scope *parent) {
    /* TODO: Once all subclasses support this function it should be made a pure
     * virtual function.
     */
}

void Decl::Check() {
    /* TODO: Once all subclasses support this function it should be made a pure
     * virtual function.
     */
}

VarDecl::VarDecl(Identifier *n, Type *t) : Decl(n) {
    Assert(n != NULL && t != NULL);
    (type=t)->SetParent(this);
}

int VarDecl::Check(List<Scope*> *scopeList, List<Type*> *typeList) {
    Scope *top = scopeList->Nth(scopeList->NumElements()-1);
    return Check(top, typeList);
}

int VarDecl::Check(Scope *scope, List<Type*> *typeList) {
    int rc = 0;

    if (Program::CheckType(type, typeList))
        rc = 1;

    if (scope->AddDecl(this))
        rc = 1;

    return rc;
}

void VarDecl::BuildScope(Scope *parent) {
    /* VarDecls don't create a new scope of their own */
    delete scope;
    scope = parent;
}

void VarDecl::Check() {
    CheckType();
}

void VarDecl::CheckType() {
    NamedType *nt = dynamic_cast<NamedType*>(type);

    if (nt == NULL)
        return;

    Scope *s = scope;
    while (s != NULL) {
        if (s->table->Lookup(nt->Name()) != NULL)
            return;
        s = s->GetParent();
    }

    type->ReportNotDeclaredIdentifier(LookingForType);
}

ClassDecl::ClassDecl(Identifier *n, NamedType *ex, List<NamedType*> *imp, List<Decl*> *m) : Decl(n) {
    // extends can be NULL, impl & mem may be empty lists but cannot be NULL
    Assert(n != NULL && imp != NULL && m != NULL);
    extends = ex;
    if (extends) extends->SetParent(this);
    (implements=imp)->SetParentAll(this);
    (members=m)->SetParentAll(this);
}

int ClassDecl::Check(List<Scope*> *scopeList, List<Type*> *typeList) {
    int rc = 0;

    Scope *global = scopeList->Nth(0);

    if (global->AddDecl(this) != 0)
        rc = 1;

    if (extends != NULL && Program::CheckClass(extends, typeList) != 0)
        rc = 1;

    for (int i = 0, n = implements->NumElements(); i < n; ++i)
        if (Program::CheckInterface(implements->Nth(i), typeList) != 0)
            rc = 1;

    Scope *classScope = new Scope;
    scopeList->Append(classScope);

    for (int i = 0, n = members->NumElements(); i < n; ++i)
        if (members->Nth(i)->Check(scopeList, typeList))
            rc = 1;

    scopeList->RemoveAt(scopeList->NumElements()-1);

    return rc;
}

int ClassDecl::AddToTypeList(List<Type*> *typeList) {
    return Program::AddUniqType(new NamedType(id), typeList);
}

void ClassDecl::BuildScope(Scope *parent) {
    scope->SetParent(parent);

    for (int i = 0, n = members->NumElements(); i < n; ++i)
        scope->AddDecl(members->Nth(i));

    for (int i = 0, n = members->NumElements(); i < n; ++i)
        members->Nth(i)->BuildScope(scope);
}

void ClassDecl::Check() {
    CheckExtends();
    CheckImplements();
}

void ClassDecl::CheckExtends() {
    if (extends == NULL)
        return;

    Decl *lookup = scope->GetParent()->table->Lookup(extends->Name());

    if (lookup == NULL || (dynamic_cast<ClassDecl*>(lookup) == NULL))
        extends->ReportNotDeclaredIdentifier(LookingForClass);
}

void ClassDecl::CheckImplements() {
    Scope *s = scope->GetParent();

    for (int i = 0, n = implements->NumElements(); i < n; ++i) {
        NamedType *nth = implements->Nth(i);
        Decl *lookup = s->table->Lookup(nth->Name());

        if (lookup == NULL || (dynamic_cast<InterfaceDecl*>(lookup) == NULL))
            nth->ReportNotDeclaredIdentifier(LookingForInterface);
    }
}

InterfaceDecl::InterfaceDecl(Identifier *n, List<Decl*> *m) : Decl(n) {
    Assert(n != NULL && m != NULL);
    (members=m)->SetParentAll(this);
}

int InterfaceDecl::Check(List<Scope*> *scopeList, List<Type*> *typeList) {
    int rc = 0;

    Scope *interfaceScope = new Scope;
    scopeList->Append(interfaceScope);

    for (int i = 0, n = members->NumElements(); i < n; ++i)
        if (members->Nth(i)->Check(scopeList, typeList))
            rc = 1;

    scopeList->RemoveAt(scopeList->NumElements()-1);

    return rc;
}

int InterfaceDecl::AddToTypeList(List<Type*> *typeList) {
    return Program::AddUniqType(new NamedType(id), typeList);
}

void InterfaceDecl::BuildScope(Scope *parent) {
    scope->SetParent(parent);

    for (int i = 0, n = members->NumElements(); i < n; ++i)
        scope->AddDecl(members->Nth(i));

    for (int i = 0, n = members->NumElements(); i < n; ++i)
        members->Nth(i)->BuildScope(scope);
}

FnDecl::FnDecl(Identifier *n, Type *r, List<VarDecl*> *d) : Decl(n) {
    Assert(n != NULL && r!= NULL && d != NULL);
    (returnType=r)->SetParent(this);
    (formals=d)->SetParentAll(this);
    body = NULL;
}

void FnDecl::SetFunctionBody(Stmt *b) {
    (body=b)->SetParent(this);
}

int FnDecl::Check(List<Scope*> *scopeList, List<Type*> *typeList) {
    Scope *top = scopeList->Nth(scopeList->NumElements()-1);

    if (top->AddDecl(this) != 0)
        return 1;

    Scope *formalsScope = new Scope;
    if (CheckFormals(formalsScope, typeList) != 0)
        return 1;
    scopeList->Append(formalsScope);

    if (body != NULL)
        body->Check(scopeList, typeList);

    scopeList->RemoveAt(scopeList->NumElements()-1);
    return 0;
}

void FnDecl::BuildScope(Scope *parent) {
    scope->SetParent(parent);

    for (int i = 0, n = formals->NumElements(); i < n; ++i)
        scope->AddDecl(formals->Nth(i));

    for (int i = 0, n = formals->NumElements(); i < n; ++i)
        formals->Nth(i)->BuildScope(scope);

    if (body)
        body->BuildScope(scope);
}

void FnDecl::Check() {
    for (int i = 0, n = formals->NumElements(); i < n; ++i)
        formals->Nth(i)->Check();
}

int FnDecl::CheckFormals(Scope *formalsScope, List<Type*> *typeList) {
    for (int i = 0, n = formals->NumElements(); i < n; ++i)
        if (formals->Nth(i)->Check(formalsScope, typeList))
            return 1;

    return 0;
}
