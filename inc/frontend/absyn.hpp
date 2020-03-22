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
using Pos = int;

struct Var;
struct Exp;
struct Decl;
struct EField;
struct TyField;
struct Typ;

using VNumber = int;
using VString = std::string;

using exp_ptr = std::shared_ptr<Exp>;
using var_ptr = std::shared_ptr<Var>;
using dec_ptr = std::shared_ptr<Decl>;
using typ_ptr = std::shared_ptr<Typ>;
using tyfield = TyField;
using efield  = EField;

using exp_list     = std::vector<exp_ptr>;
using dec_list     = std::vector<dec_ptr>;
using tyfield_list = std::vector<tyfield>;
using efield_list = std::vector<efield>;

struct Nil {
  bool operator!=(const Nil& o) { return false; }
};
struct Break {
  bool operator!=(const Nil& o) { return false; }
};

struct ASTNode {
  Pos pos;

protected:
  ASTNode(Pos pos)
      : pos(pos) {}
};

/** a Variable*/
struct Var : public ASTNode {
  struct VField {
    var_ptr var;
    Symbol sym;

    VField(var_ptr var, Symbol sym)
        : var(var)
        , sym(sym) {}
    VField(Var* var, Symbol sym)
        : var(var_ptr(var))
        , sym(sym) {}
  };

  struct Subscript {
    var_ptr var;
    exp_ptr exp;

    Subscript(var_ptr var, exp_ptr exp)
        : var(var)
        , exp(exp) {}
    Subscript(Var* var, Exp* exp)
        : var(var_ptr(var))
        , exp(exp_ptr(exp)) {}
  };

  std::variant<Symbol /*simple*/, VField, Subscript> var;

  Var(Pos pos, Symbol simple)
      : ASTNode(pos)
      , var(simple) {}
  Var(Pos pos, const VField& f)
      : ASTNode(pos)
      , var(f) {}
  Var(Pos pos, const Subscript& s)
      : ASTNode(pos)
      , var(s) {}
};

struct TyField : public ASTNode {
  Symbol name, typ;
  bool escape;

  TyField(Pos pos, const Symbol& name, const Symbol& typ)
      : ASTNode(pos)
      , name(name)
      , typ(typ) {}
};

struct EField : public ASTNode {
  Symbol name;
  exp_ptr exp;
  EField(Pos pos, const Symbol& name, const exp_ptr& exp)
      : ASTNode(pos)
      , name(name)
      , exp(exp) {}
};

/**** EXPRESSION *****/
struct Exp : ASTNode {
  // infix/prefix operators
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
  struct Op {
    op_t oper;
    exp_ptr left;
    exp_ptr right;
    Op(op_t oper, exp_ptr left, exp_ptr right)
        : oper(oper)
        , left(left)
        , right(right) {}
  };
  // function call
  struct Call {
    Symbol func;
    exp_list args;
    Call(Symbol func, const exp_list& args)
        : func(func)
        , args(args) {}
  };
  // assignment
  struct Assign {
    var_ptr var;
    exp_ptr exp;
    Assign(var_ptr var, exp_ptr exp)
        : var(var)
        , exp(exp) {}
  };
  // record definitions
  struct Record {
    Symbol typ;
    efield_list fields;
    Record(Symbol typ, const efield_list& fields)
        : typ(typ)
        , fields(fields) {}
  };
  // conditional, the alternative is optional
  struct If {
    exp_ptr pred, con;
    std::optional<exp_ptr> alt;
    If(exp_ptr pred, exp_ptr con)
        : pred(pred)
        , con(con)
        , alt({}) {}
    If(exp_ptr pred, exp_ptr con, exp_ptr alt)
        : pred(pred)
        , con(con)
        , alt(alt) {}
  };
  // while loops
  struct While {
    exp_ptr pred, body;
    While(exp_ptr pred, exp_ptr body)
        : pred(pred)
        , body(body) {}
  };
  // for loops
  struct For {
    Symbol var;
    exp_ptr lo, hi, body;
    bool escape;
    For(Symbol var, exp_ptr lo, exp_ptr hi, exp_ptr body)
        : var(var)
        , lo(lo)
        , hi(hi)
        , body(body)
        , escape(true) {}
  };
  // let bindings
  struct Let {
    dec_list decs;
    exp_ptr body;
    Let(const dec_list& decs, exp_ptr body)
        : body(body)
        , decs(decs) {}
  };
  // arrays
  struct Array {
    Symbol type;
    exp_ptr size, init;
    Array(Symbol type, exp_ptr size, exp_ptr init)
        : type(type)
        , size(size)
        , init(init) {}
  };

  // var, int, string, call, record, assignment, sequence,
  std::variant<var_ptr, VNumber, Nil, VString, Call, Record, Assign, Op,
               exp_list, If, While, For, Break, Let, Array>
      exp;

  Exp(Pos pos, const var_ptr& exp)
      : ASTNode(pos)
      , exp(exp) {}
  Exp(Pos pos, const VNumber& exp)
      : ASTNode(pos)
      , exp(exp) {}
  Exp(Pos pos, const Nil& exp)
      : ASTNode(pos)
      , exp(exp) {}
  Exp(Pos pos, const VString& exp)
      : ASTNode(pos)
      , exp(exp) {}
  Exp(Pos pos, const Call& exp)
      : ASTNode(pos)
      , exp(exp) {}
  Exp(Pos pos, const Record& exp)
      : ASTNode(pos)
      , exp(exp) {}
  Exp(Pos pos, const Assign& exp)
      : ASTNode(pos)
      , exp(exp) {}
  Exp(Pos pos, const Op& exp)
      : ASTNode(pos)
      , exp(exp) {}
  Exp(Pos pos, const exp_list& exp)
      : ASTNode(pos)
      , exp(exp) {}
  Exp(Pos pos, const If& exp)
      : ASTNode(pos)
      , exp(exp) {}
  Exp(Pos pos, const While& exp)
      : ASTNode(pos)
      , exp(exp) {}
  Exp(Pos pos, const For& exp)
      : ASTNode(pos)
      , exp(exp) {}
  Exp(Pos pos, const Break& exp)
      : ASTNode(pos)
      , exp(exp) {}
  Exp(Pos pos, const Let& exp)
      : ASTNode(pos)
      , exp(exp) {}
  Exp(Pos pos, const Array& exp)
      : ASTNode(pos)
      , exp(exp) {}
};

struct Decl : public ASTNode {
  struct Var {
    Symbol var;
    std::optional<Symbol> typ;
    exp_ptr init;
    bool escape;
    Var(const Symbol& var, const Symbol& typ, exp_ptr init)
        : var(var)
        , typ(typ)
        , init(init)
        , escape(true) {}
    Var(const Symbol& var, exp_ptr init)
        : var(var)
        , typ({})
        , init(init)
        , escape(true) {}
  };
  struct Fun {
    Symbol name;
    tyfield_list params;
    std::optional<Symbol> result;
    exp_ptr body;

    Fun(Pos pos, Symbol name, const tyfield_list& params,
        std::optional<Symbol> result, exp_ptr body)
        : name(name)
        , params(params)
        , result(result)
        , body(body) {}
  };
  struct Tydec {
    Symbol name;
    typ_ptr ty;

    Tydec(const Symbol& name, const typ_ptr& ty)
        : name(name)
        , ty(ty) {}
  };

  std::variant<Fun, Tydec, Var> decl;

  Decl(Pos pos, const Fun& decl)
      : ASTNode(pos)
      , decl(decl) {}
  Decl(Pos pos, const Tydec& decl)
      : ASTNode(pos)
      , decl(decl) {}
  Decl(Pos pos, const Var& decl)
      : ASTNode(pos)
      , decl(decl) {}
};

struct Typ : public ASTNode {
  struct Array { // newtype
    Symbol arr;
    Array(const Symbol& arr)
        : arr(arr) {}
  };

  std::variant<Symbol, Array, tyfield_list> typ;

  Typ(Pos pos, const Symbol& name)
      : ASTNode(pos)
      , typ(name) {}
  Typ(Pos pos, const Array& arr)
      : ASTNode(pos)
      , typ(arr) {}
  Typ(Pos pos, const tyfield_list& record)
      : ASTNode(pos)
      , typ(record) {}
};

var_ptr SubscriptVar(Pos pos, var_ptr var, exp_ptr exp);
var_ptr FieldVar(Pos pos, var_ptr var, Symbol sym);
var_ptr SimpleVar(Pos pos, Symbol sym);

exp_ptr VarExp(Pos pos, const var_ptr& exp);
exp_ptr IntExp(Pos pos, const VNumber& exp);
exp_ptr NumberExp(Pos pos, const VNumber& exp);
exp_ptr NilExp(Pos pos);
exp_ptr StringExp(Pos pos, const VString& exp);
exp_ptr CallExp(Pos pos, Symbol func, const exp_list& args);
exp_ptr CallExp(Pos pos, Symbol func, const list<exp_ptr>& args);
exp_ptr AssignExp(Pos pos, var_ptr var, exp_ptr exp);
exp_ptr RecordExp(Pos pos, Symbol typ, const efield_list& fields);
exp_ptr RecordExp(Pos pos, Symbol typ, const list<EField>& fields);
exp_ptr OpExp(Pos pos, Exp::op_t oper, exp_ptr left, exp_ptr right);
exp_ptr SeqExp(Pos pos, const exp_list& seq);
exp_ptr SeqExp(Pos pos, const list<exp_ptr>& seq);
exp_ptr SeqExp(Pos pos); // the empty sequence
exp_ptr IfExp(Pos pos, exp_ptr pred, exp_ptr cond);
exp_ptr IfExp(Pos pos, exp_ptr pred, exp_ptr cond, exp_ptr alt);
exp_ptr WhileExp(Pos pos, exp_ptr pred, exp_ptr body);
exp_ptr ForExp(Pos pos, Symbol var, exp_ptr lo, exp_ptr hi, exp_ptr body);
exp_ptr BreakExp(Pos pos);
exp_ptr LetExp(Pos pos, const list<dec_ptr>& decs, exp_ptr body);
exp_ptr LetExp(Pos pos, const dec_list& decs, exp_ptr body);
exp_ptr ArrayExp(Pos pos, Symbol type, exp_ptr size, exp_ptr init);

dec_ptr FunDec(Pos pos, const Decl::Fun& func);
dec_ptr TypeDec(Pos pos, Symbol name, typ_ptr ty);
dec_ptr VarDec(Pos pos, Symbol var, Symbol typ, exp_ptr init);
dec_ptr VarDec(Pos pos, Symbol var, exp_ptr init);

typ_ptr NameTy(Pos pos, Symbol name);
typ_ptr RecordTy(Pos pos, const tyfield_list& record);
typ_ptr RecordTy(Pos pos, const list<tyfield>& record);
typ_ptr ArrayTy(Pos pos, Symbol arr);

} // namespace ast
} // namespace tiger
