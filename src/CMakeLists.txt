# CMakeList.txt : CMake project for CMakeProject1, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

include_directories("../inc")
# set(INCLUDES "../inc/.h")
# set(INCLUDES "../inc/util.h" "../inc/y.tab.h" "../inc/errormsg.h" "../inc/absyn.h" "../inc/s-prabsyn.h" "../inc/symbol.h" "../inc/table.h")
add_executable (tiger "parsetest.c" "util.c" "errormsg.c" "y.tab.c" "lex.yy.c" "absyn.c" "s-prabsyn.c" "symbol.c" "table.c")
# add_executable (foo "main.c")
