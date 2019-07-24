/*
 * prabsyn.c - Print Abstract Syntax data structures. Most functions
 *           handle an instance of an abstract syntax rule.
 */

#include <stdio.h>
#include <string.h>
#include "util.h"
#include "symbol.h" /* symbol table data structures */
#include "absyn.h"  /* abstract syntax data structures */
#include "prabsyn.h" /* function prototype */

/* local function prototypes */
static void pr_var(FILE *out, A_var v, int d);
static void pr_dec(FILE *out, A_dec v, int d);
static void pr_ty(FILE *out, A_ty v, int d);
static void pr_field(FILE *out, A_field v, int d);
static void pr_fieldList(FILE *out, A_fieldList v, int d);
static void pr_expList(FILE *out, A_expList v, int d);
static void pr_fundec(FILE *out, A_fundec v, int d);
static void pr_fundecList(FILE *out, A_fundecList v, int d);
static void pr_decList(FILE *out, A_decList v, int d);
static void pr_namety(FILE *out, A_namety v, int d);
static void pr_nametyList(FILE *out, A_nametyList v, int d);
static void pr_efield(FILE *out, A_efield v, int d);
static void pr_efieldList(FILE *out, A_efieldList v, int d);

static void indent(FILE *out, int d) {
 for (int i = 0; i < d; i++)
     fprintf(out, " ");
}
static void new_line(FILE *out, int d) {
  fprintf(out, "\n");
  indent(out, d);
}

static bool is_simple(A_exp e) {
  switch (e->kind) {
  case A_varExp:
  case A_intExp:
  case A_nilExp:
  case A_stringExp:
  case A_breakExp:
    return 1;
  default:
    return 0;
  }
}

/* Print A_var types. Indent d spaces. */
static void pr_var(FILE *out, A_var v, int d) {
 switch (v->kind) {
 case A_simpleVar: {
   fprintf(out, "%s", S_name(v->u.simple));
   break;
 }
 case A_fieldVar: {
   pr_var(out, v->u.field.var, d);
   fprintf(out, ".");
   fprintf(out, "%s", S_name(v->u.field.sym));
   break;
 }
 case A_subscriptVar: {
   pr_var(out, v->u.subscript.var, d);
   fprintf(out, "[");
   pr_exp(out, v->u.subscript.exp, d);
   fprintf(out, "]");
   break;
 }
 default: {
   assert(0);
 }
 }
}

static char str_oper[][12] = {
   "+", "-", "*", "/",
   "=", "!=", "<", "<=", ">", ">="};

static int pr_oper(FILE *out, A_oper d) {
  fprintf(out, "%s", str_oper[d]);
  return strlen(str_oper[d]);
}

/* Print A_var types. Indent d spaces. */
void pr_exp(FILE *out, A_exp v, int d) {
  // printf("prabsyn::pr_exp %d", d);
  switch (v->kind) {
  case A_varExp: {
    fprintf(out, "#");
    pr_var(out, v->u.var, d+1);
    break;
  }
  case A_nilExp: {
    fprintf(out, "#nil");
    break;
  }
  case A_intExp: {
    fprintf(out, "#%d", v->u.intt);
    break;
  }
  case A_stringExp: {
    fprintf(out, "#\"%s\"", v->u.stringg);
    break;
  }
  case A_callExp: {
    string fname = S_name(v->u.call.func);
    int i = 1 + strlen(fname);
    fprintf(out, "(%s", fname);
    if(v->u.call.args) {
      fprintf(out, " ");
      pr_expList(out, v->u.call.args, d + i + 1);
    }
    fprintf(out, ")");
    break;
  }
  case A_opExp: {
    fprintf(out, "(");
    int i = 1;
    i += pr_oper(out, v->u.op.oper);
    fprintf(out, " ");
    i += 1;

    pr_exp(out, v->u.op.left, d+i);

    if (is_simple(v->u.op.right)) {
      fprintf(out, " ");
    } else {
      new_line(out, d + i);
    }
    pr_exp(out, v->u.op.right, d+i);
    fprintf(out, ")");
    break;
  }
  case A_recordExp: {
    int i = strlen("(record ");
    fprintf(out, "(record %s\n", S_name(v->u.record.typ));
    indent(out, d+i);
    pr_efieldList(out, v->u.record.fields, d+2);
    fprintf(out, ")");
    break;
  }
  case A_seqExp: {
    fprintf(out, "(seq ");
    pr_expList(out, v->u.seq, d + 5);
    fprintf(out, ")");
    break;
  }
  case A_assignExp: {
    fprintf(out, "(assign ");
    pr_var(out, v->u.assign.var, d+8);
    fprintf(out, " \n");
    indent(out, d + 8);
    pr_exp(out, v->u.assign.exp, d+8);
    fprintf(out, ")");
    break;
  }
  case A_ifExp: {
   int i = strlen("(if ");
   fprintf(out, "(if ");
   pr_exp(out, v->u.iff.test, d+i);
   new_line(out, d+i);

   pr_exp(out, v->u.iff.then, d+i);
   if (v->u.iff.elsee) { /* else is optional */
      new_line(out, d+i);
      pr_exp(out, v->u.iff.elsee, d+i);
   }
   fprintf(out, ")");
   break;
  }
  case A_whileExp: {
    int i = strlen("(while");

    fprintf(out, "(while ");
    pr_exp(out, v->u.whilee.test, d+1);

    new_line(out, d+i);
    pr_exp(out, v->u.whilee.body, d+i);
    fprintf(out, ")");
    break;
  }
  case A_forExp: {
    string var = S_name(v->u.forr.var);
    int i = strlen("(for [") + strlen(var) + 1;

    fprintf(out, "(for [%s ", var);
    pr_exp(out, v->u.forr.lo, d+i);

    if(is_simple(v->u.forr.hi)) {
      fprintf(out, " ");
    } else {
      new_line(out, d+i);
    }
    pr_exp(out, v->u.forr.hi, d+i);
    fprintf(out, "]\n");

    indent(out, d+2);
    pr_exp(out, v->u.forr.body, d+2);
    fprintf(out, ")");
    break;
  }
  case A_breakExp: {
   fprintf(out, "(break)");
   break;
  }
  case A_letExp: {
    int i = strlen("(let [");
    fprintf(out, "(let [");
    pr_decList(out, v->u.let.decs, d+i);
    fprintf(out, "]\n");
    indent(out, d+2);
    pr_exp(out, v->u.let.body, d+2);
    fprintf(out, ")");
    break;
  }
  case A_arrayExp: {
   fprintf(out, "(array %s ", S_name(v->u.array.typ));
   pr_exp(out, v->u.array.size, d+10);
   if (is_simple(v->u.array.init)) {
     fprintf(out, " ");
   } else {
     new_line(out, d + strlen("(array "));
   }
   pr_exp(out, v->u.array.init, d+10);
   fprintf(out, ")");
   break;
  }
  default:
    assert(0);
  }
}

static void pr_dec(FILE *out, A_dec v, int d) {
  switch (v->kind) {
  case A_functionDec: {
    // ignore the list thing
    // fprintf(out, "(fndec ");
    pr_fundecList(out, v->u.function, d);
    break;
  }
  case A_varDec: {
    int i = strlen("(var ");
    fprintf(out, "(var %s", S_name(v->u.var.var));

    if (v->u.var.typ) {
      fprintf(out, " :%s", S_name(v->u.var.typ));
    }

    if (is_simple(v->u.var.init)) {
      fprintf(out, " ");
    } else {
      new_line(out , d+i);
    }
    pr_exp(out, v->u.var.init, d+i);
    fprintf(out, ")");
    break;
  }
  case A_typeDec: {
    // ignore the declist thing
    // fprintf(out, "typeDec(\n");
    pr_nametyList(out, v->u.type, d);
    break;
  }
  default:
    assert(0);
  }
}

static void pr_ty(FILE *out, A_ty v, int d) {
 switch (v->kind) {
 case A_nameTy: {
   fprintf(out, "%s", S_name(v->u.name));
   break;
 }
 case A_recordTy: {
   fprintf(out, "{");
   pr_fieldList(out, v->u.record, d+1);
   fprintf(out, "}");
   break;
 }
 case A_arrayTy: {
   fprintf(out, "%s[]", S_name(v->u.array));
   break;
 }
 default:
   assert(0);
 }
}

static void pr_field(FILE *out, A_field v, int d) {
  if(v->typ)
    fprintf(out, "[");
  fprintf(out, "%s", S_name(v->name));
  if(v->typ)
    fprintf(out, ": %s]", S_name(v->typ));
}

static void pr_fieldList(FILE *out, A_fieldList v, int d) {
  if (v) {
    pr_field(out, v->head, d);
    if(d < 0 && v->tail) {
      fprintf(out, " ");
    } else if (v->tail) {
      new_line(out, d);
      pr_fieldList(out, v->tail, d);
    }
  }
}

static void pr_expList(FILE *out, A_expList v, int d) {
  if (v) {
    pr_exp(out, v->head, d);
    if(v->tail) {
      new_line(out, d);
      pr_expList(out, v->tail, d);
    }
  }
}

static void pr_fundec(FILE *out, A_fundec v, int d) {
  fprintf(out, "(fun (%s", S_name(v->name));
  if(v->params) {
    fprintf(out, " ");
    pr_fieldList(out, v->params, -1);
  }
  fprintf(out, ")");
  if (v->result) {
    fprintf(out, " : %s\n", S_name(v->result));
  }
  indent(out, d+2);
  pr_exp(out, v->body, d+2);
  fprintf(out, ")");
}

static void pr_fundecList(FILE *out, A_fundecList v, int d) {
  if (v) {
    pr_fundec(out, v->head, d);
    if(v->tail) {
      new_line(out , d);
      pr_fundecList(out, v->tail, d);
    }
  }
}

static void pr_decList(FILE *out, A_decList v, int d) {
  if (v) {
    pr_dec(out, v->head, d);
    if(v->tail) {
      new_line(out, d);
      pr_decList(out, v->tail, d);
    }
  }
}

static void pr_namety(FILE *out, A_namety v, int d) {
  int i = strlen("(type  ") + strlen(S_name(v->name));
  fprintf(out, "(type %s ", S_name(v->name));
  pr_ty(out, v->ty, d + i);
  fprintf(out, ")");
}

static void pr_nametyList(FILE *out, A_nametyList v, int d) {
  if (v) {
    pr_namety(out, v->head, d);
    if(v->tail) {
      new_line(out, d);
      pr_nametyList(out, v->tail, d);
    }
  }
}

static void pr_efield(FILE *out, A_efield v, int d) {
  fprintf(out, "[%s ", S_name(v->name));
  pr_exp(out, v->exp, d + strlen(S_name(v->name)) + 2);
  fprintf(out, "]");
}

static void pr_efieldList(FILE *out, A_efieldList v, int d) {
  if (v) {
    pr_efield(out, v->head, d);
    if(v->tail) {
      new_line(out, d);
      pr_efieldList(out, v->tail, d+1);
    }
  }
}
