/*
 * absyn.cpp - Abstract Syntax Functions. Most functions create an instance of
 * an abstract syntax rule.
 */
#include "frontend/absyn.hpp"

namespace tiger {
namespace ast {
/* Var */
var_ptr SubscriptVar(Pos pos, var_ptr var, exp_ptr exp) {
  return std::make_shared<Var>(pos, Var::Subscript(var, exp));
}
var_ptr FieldVar(Pos pos, var_ptr var, Symbol sym) {
  return std::make_shared<Var>(pos, Var::VField(var, sym));
}
var_ptr SimpleVar(Pos pos, Symbol sym) {
  return std::make_shared<Var>(pos, sym);
}

/* Exp */
exp_ptr VarExp(Pos pos, const var_ptr& exp) {
  return std::make_shared<Exp>(pos, exp);
}
exp_ptr NumberExp(Pos pos, const VNumber& exp) {
  return std::make_shared<Exp>(pos, exp);
}
exp_ptr NilExp(Pos pos) { return std::make_shared<Exp>(pos, Nil()); }
exp_ptr StringExp(Pos pos, const VString& exp) {
  return std::make_shared<Exp>(pos, exp);
}
exp_ptr CallExp(Pos pos, Symbol func, const exp_list& args) {
  return std::make_shared<Exp>(pos, Exp::Call(func, args));
}
exp_ptr AssignExp(Pos pos, var_ptr var, exp_ptr exp) {
  return std::make_shared<Exp>(pos, Exp::Assign(var, exp));
}
exp_ptr RecordExp(Pos pos, Symbol typ, const efield_list& fields) {
  return std::make_shared<Exp>(pos, Exp::Record(typ, fields));
}
exp_ptr OpExp(Pos pos, Exp::op_t oper, exp_ptr left, exp_ptr right) {
  return std::make_shared<Exp>(pos, Exp::Op(oper, left, right));
}
exp_ptr SeqExp(Pos pos, const exp_list& seq) {
  return std::make_shared<Exp>(pos, seq);
}
exp_ptr SeqExp(Pos pos) { return std::make_shared<Exp>(pos, exp_list()); }
exp_ptr SeqExp(Pos pos, const list<exp_ptr>& seq) {
  return std::make_shared<Exp>(pos, seq.to_vec());
}
exp_ptr IfExp(Pos pos, exp_ptr pred, exp_ptr cond) {
  return std::make_shared<Exp>(pos, Exp::If(pred, cond));
}
exp_ptr IfExp(Pos pos, exp_ptr pred, exp_ptr cond, exp_ptr alt) {
  return std::make_shared<Exp>(pos, Exp::If(pred, cond, alt));
}
exp_ptr WhileExp(Pos pos, exp_ptr pred, exp_ptr body) {
  return std::make_shared<Exp>(pos, Exp::While(pred, body));
}
exp_ptr ForExp(Pos pos, Symbol var, exp_ptr lo, exp_ptr hi, exp_ptr body) {
  return std::make_shared<Exp>(pos, Exp::For(var, lo, hi, body));
}
exp_ptr BreakExp(Pos pos) { return std::make_shared<Exp>(pos, Break()); }
exp_ptr LetExp(Pos pos, const dec_list& decs, exp_ptr body) {
  return std::make_shared<Exp>(pos, Exp::Let(decs, body));
}
exp_ptr ArrayExp(Pos pos, Symbol type, exp_ptr size, exp_ptr init) {
  return std::make_shared<Exp>(pos, Exp::Array(type, size, init));
}

/* declarations*/
dec_ptr FunctionDec(Pos pos, const Decl::Fun& func) {
  return std::make_shared<Decl>(pos, func);
}
dec_ptr TypeDec(Pos pos, const Decl::Tydec& type) {
  return std::make_shared<Decl>(pos, type);
}
dec_ptr VarDec(Pos pos, Symbol var, Symbol typ, exp_ptr init) {
  return std::make_shared<Decl>(pos, Decl::Var(var, typ, init));
}

typ_ptr NameTy(Pos pos, Symbol name) {
  return std::make_shared<Typ>(pos, name);
}
typ_ptr RecordTy(Pos pos, const tyfield_list& record) {
  return std::make_shared<Typ>(pos, record);
}
typ_ptr RecordTy(Pos pos, const list<tyfield>& record) {
  return std::make_shared<Typ>(pos, record.to_vec());
}
typ_ptr ArrayTy(Pos pos, Symbol arr) {
  return std::make_shared<Typ>(pos, Typ::Array(arr));
}

} // namespace ast
} // namespace tiger