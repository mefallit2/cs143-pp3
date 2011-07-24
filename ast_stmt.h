/* File: ast_stmt.h
 * ----------------
 * The Stmt class and its subclasses are used to represent
 * statements in the parse tree.  For each statment in the
 * language (for, if, return, etc.) there is a corresponding
 * node class for that construct.
 *
 * pp3: You will need to extend the Stmt classes to implement
 * semantic analysis for rules pertaining to statements.
 */

#ifndef _H_ast_stmt
#define _H_ast_stmt

#include "list.h"
#include "ast.h"
#include "hashtable.h"

class Decl;
class VarDecl;
class Expr;
class Type;
class NamedType;

class Scope
{
  private:
    Scope *parent;

  public:
    Hashtable<Decl*> *table;

  public:
    Scope() : table(new Hashtable<Decl*>) {}

    void SetParent(Scope *p) { parent = p; }
    Scope* GetParent() { return parent; }
    int AddDecl(Decl *decl);
    friend ostream& operator<<(ostream& out, Scope *s);
};

class Program : public Node
{
  protected:
     List<Decl*> *decls;

     Scope *scope;

  public:
     Program(List<Decl*> *declList);
     void Check();

  private:
     void BuildScope();
};

class Stmt : public Node
{
  protected:
    Scope *scope;

  public:
     Stmt() : Node(), scope(new Scope) {}
     Stmt(yyltype loc) : Node(loc) {}

     virtual void BuildScope(Scope *parent);
     virtual void Check();
};

class StmtBlock : public Stmt
{
  protected:
    List<VarDecl*> *decls;
    List<Stmt*> *stmts;

  public:
    StmtBlock(List<VarDecl*> *variableDeclarations, List<Stmt*> *statements);

    void BuildScope(Scope *parent);
    void Check();

  private:
};

class ConditionalStmt : public Stmt
{
  protected:
    Expr *test;
    Stmt *body;

  public:
    ConditionalStmt(Expr *testExpr, Stmt *body);

    void BuildScope(Scope *parent);
    void Check();
};

class LoopStmt : public ConditionalStmt
{
  public:
    LoopStmt(Expr *testExpr, Stmt *body)
            : ConditionalStmt(testExpr, body) {}
};

class ForStmt : public LoopStmt
{
  protected:
    Expr *init, *step;

  public:
    ForStmt(Expr *init, Expr *test, Expr *step, Stmt *body);
};

class WhileStmt : public LoopStmt
{
  public:
    WhileStmt(Expr *test, Stmt *body) : LoopStmt(test, body) {}

    void BuildScope(Scope *parent) { ConditionalStmt::BuildScope(parent); }
    void Check() { ConditionalStmt::Check(); }
};

class IfStmt : public ConditionalStmt
{
  protected:
    Stmt *elseBody;

  public:
    IfStmt(Expr *test, Stmt *thenBody, Stmt *elseBody);
};

class BreakStmt : public Stmt
{
  public:
    BreakStmt(yyltype loc) : Stmt(loc) {}
};

class ReturnStmt : public Stmt
{
  protected:
    Expr *expr;

  public:
    ReturnStmt(yyltype loc, Expr *expr);
};

class PrintStmt : public Stmt
{
  protected:
    List<Expr*> *args;

  public:
    PrintStmt(List<Expr*> *arguments);
};

#endif
