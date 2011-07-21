/* File: ast_decl.cc
 * -----------------
 * Implementation of Decl node classes.
 */
#include "ast_decl.h"
#include "ast_type.h"
#include "ast_stmt.h"
#include "errors.h"

Decl::Decl(Identifier *n) : Node(*n->GetLocation()) {
    Assert(n != NULL);
    (id=n)->SetParent(this);
}

bool Decl::operator==(const Decl &rhs) {
    return *id == *rhs.id;
}

VarDecl::VarDecl(Identifier *n, Type *t) : Decl(n) {
    Assert(n != NULL && t != NULL);
    (type=t)->SetParent(this);
}

void VarDecl::Check(List<List<Decl*>*> *scopeList) {
    return; /* TODO: Add Implementation */
}

ClassDecl::ClassDecl(Identifier *n, NamedType *ex, List<NamedType*> *imp, List<Decl*> *m) : Decl(n) {
    // extends can be NULL, impl & mem may be empty lists but cannot be NULL
    Assert(n != NULL && imp != NULL && m != NULL);
    extends = ex;
    if (extends) extends->SetParent(this);
    (implements=imp)->SetParentAll(this);
    (members=m)->SetParentAll(this);
}

void ClassDecl::Check(List<List<Decl*>*> *scopeList) {
    return; /* TODO: Add Implementation */
}

InterfaceDecl::InterfaceDecl(Identifier *n, List<Decl*> *m) : Decl(n) {
    Assert(n != NULL && m != NULL);
    (members=m)->SetParentAll(this);
}

void InterfaceDecl::Check(List<List<Decl*>*> *scopeList) {
    return; /* TODO: Add Implementation */
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

void FnDecl::Check(List<List<Decl*>*> *scopeList) {
    List<Decl*> *curScope = scopeList->Nth(scopeList->NumElements()-1);

    for (int i = 0, numElems = curScope->NumElements(); i < numElems; ++i) {
        Decl* d = curScope->Nth(i);

        /* If this Decl is already in declared in the current scope, report the
         * error and return
         */
        if (*this == *d) {
            ReportError::DeclConflict(this, d);
            return;
        }
    }

    /* If we've made it this far, this Decl must not already be declared in the
     * current scope. Thus, append it to the current scope.
     */
    curScope->Append(this);
}
