a.out: parsetest.o y.tab.o lex.yy.o errormsg.o util.o absyn.o s-prabsyn.o symbol.o table.o
	cc -g $^

parsetest.o: parsetest.c errormsg.h util.h
	cc -g -c parsetest.c

y.tab.o: y.tab.c absyn.h
	cc -g -c y.tab.c

errormsg.o: errormsg.c errormsg.h util.h
	cc -g -c errormsg.c

lex.yy.o: lex.yy.c y.tab.h errormsg.h util.h
	cc -g -c lex.yy.c

parse.o: parse.c parse.h errormsg.h absyn.h
	cc -g -c parse.c

util.o: util.c util.h
	cc -g -c util.c

absyn.o: absyn.c absyn.h util.h symbol.h
	cc -g -c absyn.c

s-prabsyn.o: s-prabsyn.c prabsyn.h absyn.h
	cc -g -c s-prabsyn.c

symbol.o: symbol.c symbol.h table.h
	cc -g -c symbol.c

table.o: table.c table.h util.h
	cc -g -c table.c

parser: lex.yy.c y.tab.c y.tab.h

lex.yy.c: tiger.lex y.tab.h absyn.h
	flex tiger.lex

y.tab.c: tiger.grm absyn.h
	yacc -dv tiger.grm

y.tab.h: y.tab.c

clean:
	rm -v y.output a.out y.tab.c y.tab.h lex.yy.c *.o
