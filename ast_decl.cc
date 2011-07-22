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

    /* Now that we know the function name has not been declared elsewhere, we
     * can begin to process its formals, return type, and body.
     */

    /* Decaf Specification (p6):
     * Formal parameters are declared in a separate scope from the function's
     * local variables (thus, a local variable can shadow a parmeter).
     *
     * Create a new list of Decls to hold the scope created by formals.
     */
    List<Decl*> *formalScope = new List<Decl*>;

    /* Decaf Specification (p6):
     * Identifiers used in the formal parameter list must be distinct.
     *
     * In order to ensure formal parameters are distinct, before a formal
     * variable declaration is added to the formal scope, it needs to be
     * checked against the Decls already in scope to ensure the requested
     * identifier is not already taken.
     */
    for (int i = 0, numElems = formals->NumElements(); i < numElems; ++i) {
        Decl *formalDecl = formals->Nth(i);

        for (int j = 0, numScope = formalScope->NumElements(); j < numScope; ++j) {
            Decl *formalScopeDecl = formalScope->Nth(j);

            /* If the requested formal declaration is already in the formal
             * scope, the identifiers must not be unique. Thus, report the
             * error and return.
             */
            if (*formalDecl == *formalScopeDecl) {
                ReportError::DeclConflict(formalDecl, formalScopeDecl);
                return;
            }
        }

        /* If we've made it this far, the requested formal variable declaration
         * must be available. Thus, add it to the formal scope.
         */
        formalScope->Append(formalDecl);
    }

    /* If we've made it this far, this FnDecl identifier and its formals do not
     * violate any Decaf scope rules.
     */

    curScope->Append(this);         // Add this FnDecl to the current scope
    scopeList->Append(formalScope); // Add the formals list to the scope list
}
