#include <stddef.h>
#include "symbol.h"
#include "semant.h"
#include "env.h"
#include "types.h"

void SEM_transProg(A_exp exp) {
    // what should the return type of a program be?
    transExp(E_base_tenv(), E_base_venv(), exp);
}

/* lookup a field by symbol in a field list */
Ty_field field_look(Ty_fieldList fields, S_symbol name) {
    for(Ty_fieldList ls = fields; ls; ls = ls->tail) {
        if (ls->head->name == name)
            return ls->head;
    }
    return NULL;
}

Ty_tyList makeFormalTyList(S_table tenv, A_fieldList ls) {
    if (ls == NULL)
        return NULL;
    else
        return Ty_TyList( lookup(tenv, hd->typ)
                        , makeFormalTyList(tenv, ls->tail));
}

Ty_ty actual_ty(Ty_ty ty) {
    if (ty && ty->kind == Ty_name)
        return actual_ty(ty->u.name.ty);
    else
        return ty;
}

void type_mismatch(int pos, Ty_ty expected, Ty_ty asserted) {
    EM_error( pos, "type error, couldn't match expected type %s with %s"
            , show_type(expected)
            , show_type(asserted));
}

struct expty transVar(S_table venv, S_table tenv, A_var a) {
    A_var v = a->u.var;

    switch(v->kind) {
    case A_simpleVar: {
        return ExpTy(NULL, S_look(venv, v->u.simple));
    }
    case A_fieldVar: {
        struct expty rec = transVar(venv, tenv, v->u.field.var);
        if (rec.ty != Ty_record)
            type_mismatch(v->u.field.var->pos, Ty_Record(NULL), rec.ty);
        Ty_field field = field_look(rec.ty->u.record, v->u.field.sym);
        if (field == NULL)
            EM_error(v->pos, "record %s has no field named '%s'", "", S_name(v->u.field.sym));
        return ExpTy(NULL, actual_ty(field->ty));
    }
    case A_subscriptVar: {
        struct expty subvar = transVar(venv, tenv, v->u.subscript.var);
        subvar.ty = actual_ty(subvar.ty);
        if(subvar.ty->kind != Ty_array)
            type_mismatch(v->u.subscript.var->pos, Ty_Array(NULL), subvar.ty);
        struct expty subexp = transExp(venv, tenv, v->u.subscript.exp);
        if(subexp.ty->kind != Ty_int)
            type_mismatch(v->u.subscript.exp->pos, Ty_Int(), subexp.ty);
        return ExpTy(NULL, subvar.ty->u.array);
    }
    }
    assert(0);
}
struct expty transExp(S_table venv, S_table tenv, A_exp a) {
    switch(a->kind) {
    case A_varExp: {
        return transVar(venv, tenv, a->u.var);
    }

    case A_nilExp: {
        return ExpTy(NULL, Ty_Nil());
    }

    case A_intExp: {
        return ExpTy(NULL, Ty_Int());
    }

    case A_stringExp: {
        return ExpTy(NULL, Ty_String());
    }

    case A_callExp: {
        S_symbol fsym = a->u.call.func;
        E_enventry x = (E_enventry) S_look(venv, fsym);
        if (x->kind != E_FunEntry)
            EM_error(v->pos, "Trying to call '%s'. Not a function.", S_name(fsym));

        // @FIXME TODO: check argument types
        for(A_expList hd_arg = a->u.call.args, Ty_ty )

        return ExpTy(NULL, actual_ty(x->u.fun.result));
    }

    case A_opExp: {
        A_oper oper = a->u.op.oper;
        struct expty left = transExp(venv, tenv, a->u.op.left);
        struct expty right= transExp(venv, tenv, a->u.op.right);
        switch(oper) {
        case A_timesOp:
        case A_divideOp:
        case A_minusOp:
        case A_plusOp : {
            if (left.ty->kind != Ty_int)
                type_mismatch(a->u.op.left->pos, Ty_Int(), left.ty); // got message?
            if (right.ty->kind != Ty_int)
                type_mismatch(a->u.op.left->pos, Ty_Int(), right.ty);
            return ExpTy(NULL, Ty_Int());
        }
        case A_eqOp:
        case A_neqOp:
        case A_ltOp:
        case A_leOp:
        case A_gtOp:
        case A_geOp:
            // @FIXME check for supported types
            if (left.ty->kind != right.ty->kind)
                type_mismatch(a->u.op.right->pos, left.ty, right.ty);
            return ExpTy(NULL, Ty_Int());
        }
        assert(0);
    }

    case A_recordExp: {
        // @FIXME todo
    }

    case  A_seqExp: {
        // @FIXME todo

    }

    case A_assignExp: {
        // @FIXME todo

    }

    case A_ifExp: {
        struct expty pred = transExp(venv, tenv, a->u.iff.test);
        if (pred.ty->kind != Ty_int)
            type_mismatch(a->u.iff.test->pos, Ty_Int(), pred.ty);
        struct expty cons = transExp(venv, tenv, a->u.iff.then);
        struct expty alte = transExp(venv, tenv, a->u.iff.elsee);
        if (cons.ty->kind != alte.ty->kind)
            type_mismatch(a->u.iff.elsee->pos, cons.ty, alte.ty);
        return ExpTy(NULL, cons.ty);
    }

    case A_whileExp: {
        // @FIXME todo

    }

    case A_forExp: {
        // @FIXME todo

    }

    case A_breakExp: {
        // @FIXME todo

    }

    case A_letExp: {
        struct expty exp;
        A_decList d;
        S_beginScope(venv); S_beginScope(tenv);

        for (d = a->u.let.decs; d; d=d->tail)
            transDec(venv, tenv, d->head);
        exp = transExp(venv, tenv, a->u.let.body);

        S_endScope(venv); S_endScope(tenv);
        return exp;
    }

    case A_arrayExp: {
        // @FIXME todo
    }
    }
    assert(0);
}

struct expty transVar(S_table venv, S_table tenv, A_var v) {
    switch(v->kind) {
    case A_simpleVar: {
        E_enventry x = (E_enventry) S_look(venv, v->u.simple);
        if (x && x->kind == E_varEntry) {
            return ExpTy(NULL, actual_ty(x->u.var.ty));
        } else {
            EM_error(v->pos, "undefined variable %s", S_name(v->u.simple));
            return ExpTy(NULL, Ty_Int());
        }
    }
    case A_fieldVar: {}
        // ..
    }
}

void transDec(S_table venv, S_table tenv, A_dec d) {
    switch(d->kind) {
    // @Note do we really typecheck here?
    case A_varDec: {
        struct expty e = transExp(venv, tenv, d->u.var.init);
        S_enter(venv, d->u.var.var, E_VarEntry(e.ty));
        break;
    }
        // Ty_Nil constrained by a Ty_Record
        // ..

    case A_typeDec: {
        S_enter(tenv, d->u.type->head->name, transTy(venv, d->u.type->head->ty));
        break;
    }
        // ..
    case A_functionDec: {
        A_fundec f = d->u.function->head;
        Ty_ty resultTy = S_look(tenv, f->result);
        Ty_tyList formalTys = makeFormalTyList(tenv, f->params);
        S_enter(venv, f->name, E_FunEntry(formalTys, resultTy));
        S_beginScope(venv);
        {
            A_fieldList l; Ty_tyList t;
            for (l=f->params, t=formalTys; l; l=l->tail, t=t->tail)
                S_enter(venv, l->head->name, E_VarEntry(t->head));

        }
        transExp(venv, tenv, d->u.function->head->body);
        break;
    }
    }

}

Ty_ty transTy(S_table tenv, A_ty t) { return NULL; }
