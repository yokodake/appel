
main : slp.o main.c
	gcc -o main main.c slp.o

util.o : util.h util.c
	gcc -c util.c

slp.o : util.o slp.h slp.c
	gcc -c slp.c util.o
