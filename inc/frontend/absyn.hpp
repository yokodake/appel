#pragma once
/*
 * absyn.hpp - Abstract Syntax Header (Chapter 4)
 *
 */

#include <memory>
#include <optional>
#include <string>
#include <variant>
#include <vector>

#include "symbol.hpp"
#include "util.hpp"

namespace tiger {
namespace ast {
using std::shared_ptr;

using Pos = int;

struct Var;
struct Exp;
struct Decl;
struct Field;

using VNumber = int;
using VString = std::string;
using exp_ptr = shared_ptr<Exp>;
using var_ptr = shared_ptr<Var>;

struct Nil {
  bool operator!=(const Nil& o) { return false; }
};
struct Break {
  bool operator!=(const Nil& o) { return false; }
};

struct ASTNode {
  Pos pos;
protected:
  ASTNode(Pos pos) : pos(pos) {}
};

/** a Variable*/
struct Var : public ASTNode {
private:
  struct VField {
    var_ptr var;
    Symbol sym;

    VField(var_ptr var, Symbol sym)
      : var(var), sym(sym) {}
    VField(Var* var, Symbol sym)
      : var(shared_ptr<Var>(var)), sym(sym) {}
  };

  struct Subscript {
    var_ptr var;
    exp_ptr exp;

    Subscript(var_ptr var, exp_ptr exp)
      : var(var), exp(exp) {}
    Subscript(Var* var, Exp* exp)
      : var(var_ptr(var)), exp(exp_ptr(exp)) {}
  };

public:
  std::variant<Symbol /*simple*/, VField, Subscript> var;

  Var(Pos pos, Symbol simple)
    : ASTNode(pos), var(simple) {}
  Var(Pos pos, const VField& f)
    : ASTNode(pos), var(f) {}
  Var(Pos pos, const Subscript& s)
    : ASTNode(pos), var(s) {}

  static inline var_ptr SubscriptVar(Pos pos, var_ptr var, exp_ptr exp) {
    return std::make_shared<Var>(pos, Subscript(var, exp));
  }
  static inline var_ptr FieldVar(Pos pos, var_ptr var, Symbol sym) {
    return std::make_shared<Var>(pos, VField(var, sym));
  }
  static inline var_ptr SimpleVar(Pos pos, Symbol sym) {
    return std::make_shared<Var>(pos, sym);
  }
};

struct Field : public ASTNode {
  Symbol name, typ;
  bool escape;
};

struct Decl : public ASTNode {};

/**** EXPRESSION *****/

/** function call */

struct Exp : ASTNode {
  // infix/prefix operators
  struct Op {
    enum op_t {
      plusOp,
      minusOp,
      timesOp,
      divideOp,
      eqOp,
      neqOp,
      ltOp,
      leOp,
      gtOp,
      geOp
    };

    op_t oper;
    exp_ptr left;
    exp_ptr right;
    Op(op_t oper, exp_ptr left, exp_ptr right)
      : oper(oper), left(left), right(right) {}
  };
  // function call
  struct Call {
    Symbol func;
    std::vector<exp_ptr> args;
    Call(Symbol func, const std::vector<exp_ptr>& args)
      : func(func), args(args) {}
  };
  // assignment
  struct Assign {
    var_ptr var;
    exp_ptr exp;
    Assign(var_ptr var, exp_ptr exp)
      : var(var), exp(exp) {}
  };
  // record definitions
  struct Record {
    Symbol typ;
    std::vector<Field> fields;
    Record(Symbol typ, const std::vector<Field>& fields)
      : typ(typ), fields(fields) {}
  };
  // conditional, the alternative is optional
  struct If {
    exp_ptr pred, con;
    std::optional<exp_ptr> alt;
    If(exp_ptr pred, exp_ptr con)
      : pred(pred), con(con), alt({}) {}
    If(exp_ptr pred, exp_ptr con, exp_ptr alt)
      : pred(pred), con(con), alt(alt) {}
  };
  // while loops
  struct While {
    exp_ptr pred, body;
    While(exp_ptr pred, exp_ptr body)
      : pred(pred), body(body) {}
  };
  // for loops
  struct For {
    Symbol var;
    exp_ptr lo, hi, body;
    bool escape;
    For(Symbol var, exp_ptr lo, exp_ptr hi, exp_ptr body)
      : var(var), lo(lo), hi(hi), body(body), escape(true) {}
  };
  // let bindings
  struct Let {
    std::vector<Decl> decs;
    exp_ptr body;
    Let(const std::vector<Decl>& decs, exp_ptr body)
      : body(body), decs(decs) {}
  };
  // arrays
  struct Array {
    Symbol type;
    exp_ptr size, init;
    Array(Symbol type, exp_ptr size, exp_ptr init)
      : type(type), size(size), init(init) {}
  };

  // var, int, string, call, record, assignment, sequence,
  std::variant<var_ptr, VNumber, Nil, VString, Call, Record, Assign, Op
              ,list<exp_ptr> , If, While, For, Break, Let, Array>
      exp;

  Exp(Pos pos, const var_ptr& exp) : ASTNode(pos), exp(exp) {}
  Exp(Pos pos, const VNumber& exp) : ASTNode(pos), exp(exp) {}
  Exp(Pos pos, const Nil& exp) : ASTNode(pos), exp(exp) {}
  Exp(Pos pos, const VString& exp) : ASTNode(pos), exp(exp) {}
  Exp(Pos pos, const Call& exp) : ASTNode(pos), exp(exp) {}
  Exp(Pos pos, const Record& exp) : ASTNode(pos), exp(exp) {}
  Exp(Pos pos, const Assign& exp) : ASTNode(pos), exp(exp) {}
  Exp(Pos pos, const Op& exp) : ASTNode(pos), exp(exp) {}
  Exp(Pos pos, const list<exp_ptr>& exp) : ASTNode(pos), exp(exp) {}
  Exp(Pos pos, const If& exp) : ASTNode(pos), exp(exp) {}
  Exp(Pos pos, const While& exp) : ASTNode(pos), exp(exp) {}
  Exp(Pos pos, const For& exp) : ASTNode(pos), exp(exp) {}
  Exp(Pos pos, const Break& exp) : ASTNode(pos), exp(exp) {}
  Exp(Pos pos, const Let& exp) : ASTNode(pos), exp(exp) {}
  Exp(Pos pos, const Array& exp) : ASTNode(pos), exp(exp) {}

  static exp_ptr VarExp(Pos pos, const var_ptr& exp) { return std::make_shared<Exp>(pos, exp); }
  static exp_ptr NumberExp(Pos pos, const VNumber& exp) { return std::make_shared<Exp>(pos, exp); }
  static exp_ptr NilExp(Pos pos) { return std::make_shared<Exp>(pos, Nil()); }
  static exp_ptr StringExp(Pos pos, const VString& exp) { return std::make_shared<Exp>(pos, exp); }
  static exp_ptr CallExp(Pos pos, Symbol func, const std::vector<exp_ptr>& args) { return std::make_shared<Exp>(pos, Call(func, args)); }
  static exp_ptr AssignExp(Pos pos, var_ptr var, exp_ptr exp) { return std::make_shared<Exp>(pos, Assign(var, exp)); }
  static exp_ptr RecordExp(Pos pos, Symbol typ, const std::vector<Field>& fields) { return std::make_shared<Exp>(pos, Record(typ, fields)); }
  static exp_ptr OpExp(Pos pos, Op::op_t oper, exp_ptr left, exp_ptr right) { return std::make_shared<Exp>(pos, Op(oper, left, right)); }
  static exp_ptr SeqExp(Pos pos, const list<exp_ptr>& seq) { return std::make_shared<Exp>(pos, seq); }
  static exp_ptr IfExp(Pos pos, exp_ptr pred, exp_ptr cond) { return std::make_shared<Exp>(pos, If(pred, cond)); }
  static exp_ptr IfExp(Pos pos, exp_ptr pred, exp_ptr cond, exp_ptr alt) { return std::make_shared<Exp>(pos, If(pred, cond, alt)); }
  static exp_ptr WhileExp(Pos pos, exp_ptr pred, exp_ptr body) { return std::make_shared<Exp>(pos, While(pred, body)); }
  static exp_ptr ForExp(Pos pos, Symbol var, exp_ptr lo, exp_ptr hi, exp_ptr body) { return std::make_shared<Exp>(pos, For(var, lo, hi, body)); }
  static exp_ptr BreakExp(Pos pos) { return std::make_shared<Exp>(pos, Break()); }
  static exp_ptr LetExp(Pos pos, const std::vector<Decl>& decs, exp_ptr body) { return std::make_shared<Exp>(pos, Let(decs, body)); }
  static exp_ptr ArrayExp(Pos pos, Symbol type, exp_ptr size, exp_ptr init) { return std::make_shared<Exp>(pos, Array(type, size, init)); }
};

}  // namespace ast
}  // namespace tiger
