/* File: ast_type.h
 * ----------------
 * In our parse tree, Type nodes are used to represent and
 * store type information. The base Type class is used
 * for built-in types, the NamedType for classes and interfaces,
 * and the ArrayType for arrays of other types.
 *
 * pp3: You will need to extend the Type classes to implement
 * the type system and rules for type equivalency and compatibility.
 */

#ifndef _H_ast_type
#define _H_ast_type

#include "ast.h"
#include "list.h"
#include <iostream>
using namespace std;

class Type : public Node
{
  protected:
    char *typeName;

  public :
    static Type *intType, *doubleType, *boolType, *voidType,
                *nullType, *stringType, *errorType;

    Type(yyltype loc) : Node(loc) {}
    Type(const char *str);

    virtual void PrintToStream(ostream& out) { out << typeName; }
    friend ostream& operator<<(ostream& out, Type *t) { t->PrintToStream(out); return out; }
    virtual bool IsEqualTo(Type *other) { return this == other; }
    virtual bool IsEquivalentTo(Type *other) { return IsEqualTo(other); }
    virtual void ReportNotDeclaredIdentifier() { return; }
};

class NamedType : public Type
{
  protected:
    Identifier *id;

  public:
    NamedType(Identifier *i);

    void PrintToStream(ostream& out) { out << id; }
    void ReportNotDeclaredIdentifier();
    bool IsEqualTo(Type *other);
    bool IsEquivalentTo(Type *other) { return IsEqualTo(other); }
};

class ArrayType : public Type
{
  protected:
    Type *elemType;

  public:
    ArrayType(yyltype loc, Type *elemType);

    void PrintToStream(ostream& out) { out << elemType << "[]"; }
};

#endif
