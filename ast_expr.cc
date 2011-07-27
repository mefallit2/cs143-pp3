/* File: ast_expr.cc
 * -----------------
 * Implementation of expression node classes.
 */

#include <string.h>
#include "ast_expr.h"
#include "ast_type.h"
#include "ast_decl.h"

Type* Expr::GetType() {
    /* TODO: Once all sublcasses support this function it should be made a pure
    * virtual function.
    */
    return Type::errorType;
}

bool Expr::IsInClassScope() {
    Scope *s = scope;
    while (s != NULL) {
        if (s->GetClassScope())
            return true;
        s = s->GetParent();
    }

    return false;
}

Decl* Expr::GetFieldDecl(Identifier *f, Type *b) {
    NamedType *t = dynamic_cast<NamedType*>(b);

    while (t != NULL) {
        Decl *d = Program::gScope->table->Lookup(t->Name());
        ClassDecl *c = dynamic_cast<ClassDecl*>(d);

        Decl *fieldDecl;
        if (c != NULL && (fieldDecl = GetFieldDecl(f, c->GetScope())) != NULL)
            return fieldDecl;

        t = c->GetExtends();
    }

    return GetFieldDecl(f, scope);
}

Decl* Expr::GetFieldDecl(Identifier *f, Scope *s) {
    while (s != NULL) {
        Decl *lookup;
        if ((lookup = s->table->Lookup(f->Name())) != NULL)
            return lookup;

        s = s->GetParent();
    }

    return NULL;
}

IntConstant::IntConstant(yyltype loc, int val) : Expr(loc) {
    value = val;
}

Type* IntConstant::GetType() {
    return Type::intType;
}

DoubleConstant::DoubleConstant(yyltype loc, double val) : Expr(loc) {
    value = val;
}

Type* DoubleConstant::GetType() {
    return Type::doubleType;
}

BoolConstant::BoolConstant(yyltype loc, bool val) : Expr(loc) {
    value = val;
}

Type* BoolConstant::GetType() {
    return Type::boolType;
}

StringConstant::StringConstant(yyltype loc, const char *val) : Expr(loc) {
    Assert(val != NULL);
    value = strdup(val);
}

Type* StringConstant::GetType() {
    return Type::stringType;
}

Type* NullConstant::GetType() {
    return Type::nullType;
}

Operator::Operator(yyltype loc, const char *tok) : Node(loc) {
    Assert(tok != NULL);
    strncpy(tokenString, tok, sizeof(tokenString));
}

CompoundExpr::CompoundExpr(Expr *l, Operator *o, Expr *r)
  : Expr(Join(l->GetLocation(), r->GetLocation())) {
    Assert(l != NULL && o != NULL && r != NULL);
    (op=o)->SetParent(this);
    (left=l)->SetParent(this);
    (right=r)->SetParent(this);
}

CompoundExpr::CompoundExpr(Operator *o, Expr *r)
  : Expr(Join(o->GetLocation(), r->GetLocation())) {
    Assert(o != NULL && r != NULL);
    left = NULL;
    (op=o)->SetParent(this);
    (right=r)->SetParent(this);
}

void CompoundExpr::BuildScope(Scope *parent) {
    scope->SetParent(parent);

    if (left != NULL)
        left->BuildScope(scope);

    right->BuildScope(scope);
}

void CompoundExpr::Check() {
    if (left != NULL)
        left->Check();

    right->Check();
}

Type* ArithmeticExpr::GetType() {
    Type *rtype = right->GetType();

    if (left == NULL) {
        if (rtype->IsEquivalentTo(Type::intType) ||
            rtype->IsEquivalentTo(Type::doubleType))
            return rtype;
        else
            return Type::errorType;
    }

    Type *ltype = left->GetType();

    if (ltype->IsEquivalentTo(Type::intType) &&
        rtype->IsEquivalentTo(Type::intType))
        return ltype;

    if (ltype->IsEquivalentTo(Type::doubleType) &&
        rtype->IsEquivalentTo(Type::doubleType))
        return ltype;

    return Type::errorType;
}

void ArithmeticExpr::Check() {
    if (left != NULL)
        left->Check();

    right->Check();

    Type *rtype = right->GetType();

    if (left == NULL) {
        if (rtype->IsEquivalentTo(Type::intType) ||
            rtype->IsEquivalentTo(Type::doubleType))
            return;
        else
            ReportError::IncompatibleOperand(op, rtype);
            return;
    }

    Type *ltype = left->GetType();

    if (ltype->IsEquivalentTo(Type::intType) &&
        rtype->IsEquivalentTo(Type::intType))
        return;

    if (ltype->IsEquivalentTo(Type::doubleType) &&
        rtype->IsEquivalentTo(Type::doubleType))
        return;

    ReportError::IncompatibleOperands(op, ltype, rtype);
}

Type* AssignExpr::GetType() {
    Type *ltype = left->GetType();
    Type *rtype = right->GetType();

    if (!rtype->IsEquivalentTo(ltype))
        return Type::errorType;

    return ltype;
}

void AssignExpr::Check() {
    left->Check();
    right->Check();

    Type *ltype = left->GetType();
    Type *rtype = right->GetType();

    if (!rtype->IsEquivalentTo(ltype))
        ReportError::IncompatibleOperands(op, ltype, rtype);
}

void This::Check() {
    if (!IsInClassScope())
        ReportError::ThisOutsideClassScope(this);
}

ArrayAccess::ArrayAccess(yyltype loc, Expr *b, Expr *s) : LValue(loc) {
    (base=b)->SetParent(this);
    (subscript=s)->SetParent(this);
}

Type* ArrayAccess::GetType() {
    ArrayType *t = dynamic_cast<ArrayType*>(base->GetType());
    if (t == NULL)
        return Type::errorType;

    return t->GetElemType();
}

void ArrayAccess::BuildScope(Scope *parent) {
    scope->SetParent(parent);

    base->BuildScope(scope);
    subscript->BuildScope(scope);
}

void ArrayAccess::Check() {
    base->Check();
    subscript->Check();

    ArrayType *t = dynamic_cast<ArrayType*>(base->GetType());
    if (t == NULL)
        ReportError::BracketsOnNonArray(base);

    if (!subscript->GetType()->IsEqualTo(Type::intType))
        ReportError::SubscriptNotInteger(subscript);
}

FieldAccess::FieldAccess(Expr *b, Identifier *f)
  : LValue(b? Join(b->GetLocation(), f->GetLocation()) : *f->GetLocation()) {
    Assert(f != NULL); // b can be be NULL (just means no explicit base)
    base = b;
    if (base) base->SetParent(this);
    (field=f)->SetParent(this);
}

Type* FieldAccess::GetType() {
    if (base == NULL) {
        VarDecl *d = dynamic_cast<VarDecl*>(GetFieldDecl(field, scope));
        if (d == NULL)
            return Type::errorType;

        return d->GetType();
    }

    Type *t = base->GetType();
    VarDecl *d = dynamic_cast<VarDecl*>(GetFieldDecl(field, t));
    if (d == NULL)
        return Type::errorType;

    return d->GetType();
}

void FieldAccess::BuildScope(Scope *parent) {
    scope->SetParent(parent);

    if (base != NULL)
        base->BuildScope(scope);
}

void FieldAccess::Check() {
    if (base == NULL) {
        if (GetFieldDecl(field, scope) == NULL)
            ReportError::IdentifierNotDeclared(field, LookingForVariable);
        return;
    }

    base->Check();

    Type *t = base->GetType();

    if (GetFieldDecl(field, t) == NULL) {
        ReportError::FieldNotFoundInBase(field, t);
        return;
    }

    if (!IsInClassScope()) {
        ReportError::InaccessibleField(field, t);
        return;
    }
}

Call::Call(yyltype loc, Expr *b, Identifier *f, List<Expr*> *a) : Expr(loc)  {
    Assert(f != NULL && a != NULL); // b can be be NULL (just means no explicit base)
    base = b;
    if (base) base->SetParent(this);
    (field=f)->SetParent(this);
    (actuals=a)->SetParentAll(this);
}

NewExpr::NewExpr(yyltype loc, NamedType *c) : Expr(loc) {
  Assert(c != NULL);
  (cType=c)->SetParent(this);
}

NewArrayExpr::NewArrayExpr(yyltype loc, Expr *sz, Type *et) : Expr(loc) {
    Assert(sz != NULL && et != NULL);
    (size=sz)->SetParent(this);
    (elemType=et)->SetParent(this);
}

Type* NewArrayExpr::GetType() {
    return new ArrayType(elemType);
}

void NewArrayExpr::BuildScope(Scope *parent) {
    scope->SetParent(parent);

    size->BuildScope(scope);
}

void NewArrayExpr::Check() {
    size->Check();

    if (!size->GetType()->IsEqualTo(Type::intType))
        ReportError::NewArraySizeNotInteger(size);
}
