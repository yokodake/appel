#include <stdio.h>
#include <string.h>

#include "slp.h"

/***************************/
/* exo1 */
int max(int a, int b) {
    return a > b ? a : b;
}

int expList_len(A_expList ls) {
    int r = 1;
    A_expList t = ls;
    while(t->kind != A_lastExpList) {
        r++;
        t = t->u.pair.tail;
    }
    return r;
}

int maxargs(A_stm p) {
    int m;
    switch(p->kind) {
    case A_compoundStm:
        m = maxargs(p->u.compound.stm1);
        return max(m, maxargs(p->u.compound.stm2));
    case A_printStm:
        return expList_len(p->u.print.exps);
    case A_assignStm:
        if (p->u.assign.exp->kind == A_eseqExp)
            return maxargs(p->u.assign.exp->u.eseq.stm);
    default:
        return 0;
    }
    return m;
}

/***************************/
/* exo2 */
typedef struct table_* table;
struct table_ {string id; int value; table tail; };
table Table(string id, int value, table tail) {
    table t = malloc(sizeof(*t));
    t->id = id;
    t->value = value;
    t->tail = tail;
    return t;
}
int lookup(string id, table tail) {
    table tl = tail;
    while (tl != NULL) {
        if (strcmp(id, tl->id) == 0)
            return tl->value;
    }
    printf("%s : not found" , id);
    exit(EXIT_FAILURE);
}

typedef struct expRes expRes;
struct expRes {int i; table t;};
expRes ExpRes(int i, table t) {
    expRes r;
    r.i = i;
    r.t = t;
    return r;
}
table interpStm(A_stm, table);
expRes interpExp(A_exp, table);

table interpStm(A_stm s, table t) {
    if (s->kind == A_compoundStm) {
        table nt = interpStm(s->u.compound.stm1, t);
        return interpStm(s->u.compound.stm2, nt);
    } else if (s->kind == A_assignStm) {
        expRes er = interpExp(s->u.assign.exp, t);
        return Table(s->u.assign.id, er.i, er.t);
    } else if (s->kind == A_printStm) {
        A_expList exps = s->u.print.exps;
        expRes er; er.t = t;
        while (exps->kind != A_lastExpList) {
            er = interpExp(exps->u.pair.head, er.t);
            printf("%d ", er.i);
            exps = exps->u.pair.tail;
        }
        er = interpExp(exps->u.last, er.t);
        printf("%d\n", er.i);
        return er.t;
    }
}

expRes eval(A_binop op, A_exp left, A_exp right, table t) {
    expRes l = interpExp(left, t);
    expRes r = interpExp(right, l.t);
    int v;
    switch(op) {
    case A_plus:
        v = l.i + r.i;
        break;
    case A_minus:
        v = l.i - r.i;
        break;
    case A_times:
        v = l.i * r.i;
        break;
    case A_div:
        v = l.i / r.i;
        break;
    }
    expRes o;
    o.i = v; o.t = r.t;
    return o;
}

expRes interpExp(A_exp exp, table t) {
    expRes r;
    switch(exp->kind) {
    case A_idExp:
        r.i = lookup(exp->u.id, t);
        r.t = t;
        return r;
    case A_numExp:
        r.i = exp->u.num;
        r.t = t;
        return r;
    case A_opExp:
        return eval(exp->u.op.oper,
                    exp->u.op.left,
                    exp->u.op.right,
                    t);
    case A_eseqExp:
        return interpExp(exp->u.eseq.exp,
                         interpStm(exp->u.eseq.stm, t));
    }
}


void main(void) {
    A_stm prog =
        A_CompoundStm(A_AssignStm("a",
                                  A_OpExp(A_NumExp(5), A_plus, A_NumExp(3))),
          A_CompoundStm(A_AssignStm("b",
            A_EseqExp(A_PrintStm(A_PairExpList(A_IdExp("a"),
                                               A_LastExpList(A_OpExp(A_IdExp("a"),
                                                                     A_minus,
                                                                     A_NumExp(1))))),
                      A_OpExp(A_NumExp(10), A_times, A_IdExp("a")))),
                        A_PrintStm(A_LastExpList(A_IdExp("b")))));
    printf("%d\n", maxargs(prog));
    puts("----");
    interpStm(prog, NULL);
}
