/* File: ast_stmt.cc
 * -----------------
 * Implementation of statement node classes.
 */
#include "ast_stmt.h"
#include "ast_type.h"
#include "ast_decl.h"
#include "ast_expr.h"
#include "errors.h"
#include "ast_type.h"

int Scope::AddUniqDecl(Decl *d) {
    for (int i = 0, n = scope->NumElements(); i < n; ++i) {
        Decl *nth = scope->Nth(i);

        // If this Decl is already in declared, report the error
        if (*nth == *d) {
            ReportError::DeclConflict(d, nth);
            return 1;
        }
    }

    scope->Append(d);
    return 0;
}

int Scope::RmUniqDecl(Decl *d) {
    for (int i = 0, numElems = scope->NumElements(); i < numElems; ++i) {
        Decl *nth = scope->Nth(i);

        if (*nth == *d) {
            scope->RemoveAt(i);
            return 0;
        }
    }
    return 1;
}

ostream& operator<<(ostream& out, Scope *s) {
    out << "========== Scope ==========" << std::endl;
    for (int i = 0, n = s->scope->NumElements(); i < n; ++i)
        out << s->scope->Nth(i) << std::endl;
    return out;
}

Program::Program(List<Decl*> *d) :
scopeList(new List<Scope*>),
typeList(new List<Type*>)
{
    Assert(d != NULL);
    (decls=d)->SetParentAll(this);
    scopeList->Append(new Scope); // Initial empty global scope

    // Append all primitive types
    typeList->Append(Type::intType);
    typeList->Append(Type::doubleType);
    typeList->Append(Type::boolType);
    typeList->Append(Type::voidType);
    typeList->Append(Type::nullType);
    typeList->Append(Type::stringType);
    typeList->Append(Type::errorType);
}

void Program::Check() {
    /* pp3: here is where the semantic analyzer is kicked off.
     *      The general idea is perform a tree traversal of the
     *      entire program, examining all constructs for compliance
     *      with the semantic rules.  Each node can have its own way of
     *      checking itself, which makes for a great use of inheritance
     *      and polymorphism in the node classes.
     */

    for (int i = 0, numElems = decls->NumElements(); i < numElems; i++) {
        Decl* d = decls->Nth(i);

        ClassDecl *cd = dynamic_cast<ClassDecl*>(d);
        if (cd != NULL) {
            cd->AddToTypeList(typeList);
            continue;
        }

        InterfaceDecl *id = dynamic_cast<InterfaceDecl*>(d);
        if (id != NULL) {
            id->AddToTypeList(typeList);
            continue;
        }
    }

    for (int i = 0, numElems = decls->NumElements(); i < numElems; i++)
        decls->Nth(i)->Check(scopeList, typeList);
}

bool Program::IsEquivalentTypeInList(Type *type, List<Type*> *typeList) {
    for (int i = 0, n = typeList->NumElements(); i < n; ++i) {
        if (type->IsEquivalentTo(typeList->Nth(i)))
            return true;
    }

    return false;
}

int Program::CheckType(Type *type, List<Type*> *typeList) {
    if (IsEquivalentTypeInList(type, typeList))
        return 0;

    type->ReportNotDeclaredIdentifier(LookingForType);
    return 1;
}

int Program::CheckClass(NamedType *type, List<Type*> *typeList) {
    if (IsEquivalentTypeInList(type, typeList))
        return 0;

    type->ReportNotDeclaredIdentifier(LookingForClass);
    return 1;
}

int Program::CheckInterface(NamedType *type, List<Type*> *typeList) {
    if (IsEquivalentTypeInList(type, typeList))
        return 0;

    type->ReportNotDeclaredIdentifier(LookingForInterface);
    return 1;
}

int Program::AddUniqType(Type *type, List<Type*> *typeList) {
    for (int i = 0, n = typeList->NumElements(); i < n; ++i) {
        if (type->IsEqualTo(typeList->Nth(i))) {
            return 1;
        }
    }

    typeList->Append(type);
    return 0;
}

int Stmt::Check(List<Scope*> *scopeList, List<Type*> *typeList) {
    /* TODO: Once all sublcasses support this function it should be made a pure
     * virtual function.
     */
    return 0;
}

StmtBlock::StmtBlock(List<VarDecl*> *d, List<Stmt*> *s) {
    Assert(d != NULL && s != NULL);
    (decls=d)->SetParentAll(this);
    (stmts=s)->SetParentAll(this);
}

int StmtBlock::Check(List<Scope*> *scopeList, List<Type*> *typeList) {
    int rc = 0;

    Scope *blockScope = new Scope;
    if (CheckDecls(blockScope, typeList) != 0)
        rc = 1;
    scopeList->Append(blockScope);

    for (int i = 0, n = stmts->NumElements(); i < n; ++i)
        if (stmts->Nth(i)->Check(scopeList, typeList) != 0)
            rc = 1;

    scopeList->RemoveAt(scopeList->NumElements()-1);

    return rc;
}

int StmtBlock::CheckDecls(Scope *blockScope, List<Type*> *typeList) {
    for (int i = 0, n = decls->NumElements(); i < n; ++i)
        if (decls->Nth(i)->Check(blockScope, typeList) != 0)
            return 1;

    return 0;
}

ConditionalStmt::ConditionalStmt(Expr *t, Stmt *b) {
    Assert(t != NULL && b != NULL);
    (test=t)->SetParent(this);
    (body=b)->SetParent(this);
}

int ConditionalStmt::Check(List<Scope*> *scopeList, List<Type*> *typeList) {
    int rc = 0;

    Scope *bodyScope = new Scope;
    scopeList->Append(bodyScope);

    if (body->Check(scopeList, typeList) != 0)
        rc = 1;

    scopeList->RemoveAt(scopeList->NumElements()-1);

    return rc;
}

ForStmt::ForStmt(Expr *i, Expr *t, Expr *s, Stmt *b): LoopStmt(t, b) {
    Assert(i != NULL && t != NULL && s != NULL && b != NULL);
    (init=i)->SetParent(this);
    (step=s)->SetParent(this);
}

IfStmt::IfStmt(Expr *t, Stmt *tb, Stmt *eb): ConditionalStmt(t, tb) {
    Assert(t != NULL && tb != NULL); // else can be NULL
    elseBody = eb;
    if (elseBody) elseBody->SetParent(this);
}

ReturnStmt::ReturnStmt(yyltype loc, Expr *e) : Stmt(loc) {
    Assert(e != NULL);
    (expr=e)->SetParent(this);
}

PrintStmt::PrintStmt(List<Expr*> *a) {
    Assert(a != NULL);
    (args=a)->SetParentAll(this);
}
