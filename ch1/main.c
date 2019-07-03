#include "slp.h"
#include <stdio.h>

/// exo1
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

/// exo2
typedef struct table_* table;
struct table_ {string id; int value; table tail};
table Table(string id, int value, table tail) {
    table t = malloc(sizeof(*t));
    t->id = id;
    t->value = value;
    t->tail = tail;
    return t;
}
struct expRes_ {int i; table t;};
typedef struct expRes_* expRes;
expRes ExpRes(int i, table t) {
    expRes r = malloc(sizeof(*r));
    r->i = i;
    r->t = t;
    return r;
}
void interpStm(A_stm, table);
expRes interpExp(A_exp, table);

table interpStm(A_stm s, table t) {
    if (s->kind == A_compoundStm) {
        table nt = interpStm(s->u.compound.stm1, t);
        return interpStm(s->u.compound.stm2, nt);
    } else if (s->kind == A_assignStm) {
        expRes er = interpExp(s->u.assign.exp, t);
        return Table(s->u.assign.id, er->i, er->t);
    } else if (s->kind == A_printStm) {
        expList exps = s->u.print.exps;
        expRes er;
        while (exps->kind != A_lastExpList) {
            er = interpExp()
        }
        er = interpExp(exps->last, er->t);
        printf("%d", )
        return;
    }
}
expRes interpExp(A_exp exp, table t) {
    switch(root->kind) {
    case A_idExp:
    case A_numExp:
    case A_opExp:
    case A_eseqExp:
    }
    return 0;
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
    printf("%d", maxargs(prog));
}
