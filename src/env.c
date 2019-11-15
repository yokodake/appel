#include "symbol.h"
#include "types.h"
#include "env.h"


E_enventry E_VarEntry(Ty_ty ty) {
    E_enventry e = checked_malloc(sizeof(*e));
    e->kind = E_varEntry;
    e->u.var.ty = ty;
    return e;
}

E_enventry E_FunEntry(Ty_tyList formals, Ty_ty result) {
    E_enventry e = checked_malloc(sizeof(*e));
    e->kind = E_funEntry;
    e->u.fun.formals = formals;
    e->u.fun.result  = result;
    return e;
}


S_table E_base_tenv(void) {
    S_table t = S_empty();
    S_enter(t, S_Symbol("string"), Ty_String());
    S_enter(t, S_Symbol("nil"), Ty_Nil());
    S_enter(t, S_Symbol("int"), Ty_Int());
    S_enter(t, S_Symbol("void"), Ty_Void());
    return t;
}
S_table E_base_venv(void) {
    S_table t = S_empty();
    S_enter(t, S_Symbol("nil"), E_VarEntry(Ty_Nil()));
    return t;
}
