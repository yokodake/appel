/*
 * semant.h -
 *
 * performs semantic analysis - including type-checking - of abstract syntax.
 */
#include "symbol.h"
#include "types.h"
#include "absyn.h"

/* dummy */
typedef void *Tr_exp;

struct expty {Tr_exp exp; Ty_ty ty;};

struct expty ExpTy(Tr_exp exp, Ty_ty ty) {
    struct expty e;
    e.exp=exp; e.ty=ty;
    return e;
}

void SEM_transProg(A_exp exp);

struct expty transVar(S_table venv, S_table tenv, A_var v);
struct expty transExp(S_table venv, S_table tenv, A_exp a);
void         transDec(S_table venv, S_table tenv, A_dec d);
Ty_ty        transTy (              S_table tenv, A_ty  a);
