#!/bin/sh

# run lex and compile the resulting C analyser
lex $1
clang -o $2 lex.yy.c
