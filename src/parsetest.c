#include <stdio.h>
#include <stdlib.h>
#include "absyn.h"
#include "errormsg.h"
#include "prabsyn.h"
#include "util.h"

extern int yyparse(void);
extern A_exp absyn_root;

void parse(string fname) {
    EM_reset(fname);
    if (yyparse() == 0) {/* parsing worked */
        fprintf(stderr,"Parsing successful!\n");
    } else {
        fprintf(stderr,"Parsing failed\n");
        exit(EXIT_FAILURE);
    }
}


int main(int argc, char **argv) {
 if (argc!=2) {
     fprintf(stderr,"usage: a.out filename\n");
     exit(EXIT_FAILURE);
 }
 parse(argv[1]);
 pr_exp(stdout, absyn_root, 0);
 puts("");
 return 0;
}
