y_hdr = y.tab.h
y_src = y.tab.c
lex   = lex.yy.c

incdir = ../inc
INC = -I../inc
DFLAGS = -Wall
CC     = gcc $(DFLAGS) $(INC)
CC_    = gcc $(INC)

list = errormsg.h util.h absyn.h symbol.h prabsyn.h table.h

a.out: parsetest.o y.tab.o lex.yy.o errormsg.o util.o absyn.o s-prabsyn.o symbol.o table.o
	$(CC) -g $^

$(list) : %: ../inc/%
	echo $@

parsetest.o: parsetest.c errormsg.h util.h
	$(CC) -g -c parsetest.c

y.tab.o: $(y_src) absyn.h
	$(CC_) -g -c $(y_src)

errormsg.o: errormsg.c errormsg.h util.h
	$(CC) -g -c errormsg.c

lex.yy.o: $(lex) $(y_hdr) errormsg.h util.h
	$(CC_) -g -c $(lex)

parse.o: parse.c parse.h errormsg.h absyn.h
	$(CC) -g -c parse.c

util.o: util.c util.h
	$(CC) -g -c util.c

absyn.o: absyn.c absyn.h util.h symbol.h
	$(CC) -g -c absyn.c

s-prabsyn.o: s-prabsyn.c prabsyn.h absyn.h
	$(CC) -g -c s-prabsyn.c

symbol.o: symbol.c symbol.h table.h util.h
	$(CC) -g -c symbol.c

table.o: table.c table.h util.h
	$(CC) -g -c table.c

parser: $(lex) $(y_src) $(y_hdr)

$(lex): tiger.lex $(y_hdr) absyn.h
	flex tiger.lex

$(y_src): tiger.grm absyn.h
	bison -dv tiger.grm -o $(y_src)

$(y_hdr): $(y_src)

clean:
	rm -v y.output a.out $(y_src) $(y_hdr) $(lex) *.o
