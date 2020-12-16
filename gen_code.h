#include "structures.h"
#include "symbol_table.h"
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void start_program(program *my_program);
void function_def(program *node);
void function_dec(program *node);
void function_body(program *body);
char *var_type(char *type);
void expression(program *expr);