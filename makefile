y_hdr = y.tab.h
y_src = y.tab.c
x_src = lex.yy.c

IDIR = ./inc
INC = -I$(IDIR)

OUT = ./out
LIB = ./lib
SRC = ./src
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

$(SRC)/$(x_src): $(SRC)/tiger.lex
	flex -o $@ $<

$(SRC)/$(y_src): $(SRC)/tiger.grm
	bison -dv $(SRC)/tiger.grm -o $@
	mv -v $(SRC)/$(y_hdr) $(IDIR)/

$(IDIR)/$(y_hdr): $(SRC)/$(y_src)

.PHONY: build clean

clean:
	rm -v $(SRC)/y.output $(OUT)/*.o $(SRC)/$(y_src) $(IDIR)/$(y_hdr) $(SRC)/$(x_src)
