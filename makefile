y_hdr = y.tab.h
y_src = y.tab.c
x_src = lex.yy.c

IDIR = ./inc
INC = -I$(IDIR)

OUT = ./out
LIB = ./lib
SRC = ./src
GEN = ./src/frontend/
SRC_FILES = absyn.c env.c errormsg.c semant.c s-prabsyn.c symbol.c table.c types.c util.c parsetest.c
OBJ = $(y_src:%.c= $(OUT)/%.o) $(x_src:%.c= $(OUT)/%.o) $(SRC_FILES:%.c= $(OUT)/%.o)

DFLAGS = -Wall
CC     = gcc $(DFLAGS) $(INC) $(LIBS)
CC_    = gcc $(INC)

build: $(OBJ)
	@mkdir -p $(OUT)
	$(CC) -g $^ -o $(OUT)/a.out

$(OBJ): $(OUT)/%.o: $(SRC)/%.c # $(IDIR)/%.h
	@mkdir -p $(@D)
	$(CC_) -c -o $@ $< $(DFLAGS)

$(GEN)/$(x_src): $(GEN)/tiger.lex
	flex -o $@ $<

$(GEN)/$(y_src): $(GEN)/tiger.grm
	bison -dv $(GEN)/tiger.grm -o $@
	mv -v $(GEN)/$(y_hdr) $(IDIR)/frontend/

$(IDIR)/$(y_hdr): $(SRC)/$(y_src)

.PHONY: build clean

clean:
	rm -v $(SRC)/y.output $(OUT)/*.o $(SRC)/$(y_src) $(IDIR)/$(y_hdr) $(SRC)/$(x_src)
