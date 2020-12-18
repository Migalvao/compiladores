#include "structures.h"
#include "symbol_table.h"
#include "functions.h"
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define VALUE_SIZE 50

void start_program(program *my_program);
void function_def(program *node);
void function_dec(program *node);
void function_body(program *body);
char *var_type(char *type);
char *expression(program *expr, bool to_double);
void declaration(program *node);
int charlit_to_int(char *string);
int intlit_to_int(char *string);
int size(char *type);
void print_tab(int local_indent);
void i32_to_double(char *value);
void check_gen_while(program *node);