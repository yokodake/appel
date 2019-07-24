# CMakeList.txt : CMake project for CMakeProject1, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# add_executable (tiger "util.c" "util.h" "errormsg.c" "errormsg.h" "y.tab.h" "y.tab.c" "lex.yy.c") 
add_executable (tiger "parsetest.c" "util.c" "util.h" "errormsg.c" "errormsg.h" "y.tab.h" "y.tab.c" "lex.yy.c" "absyn.h" "absyn.c" "s-prabsyn.c" "prabsyn.h" "symbol.c" "symbol.h" "table.h" "table.c")
add_executable (foo "main.c")
