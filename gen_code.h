#include "structures.h"
#include "symbol_table.h"
#include "functions.h"
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define VALUE_SIZE 50

typedef struct t1
{
    char *var_name;
    struct _s1 *node;
    struct t1 *next;
} global_var_expression;

void start_program(program *my_program);
void function_def(program *node);
void function_dec(program *node);
bool function_body(program *func_body);
char *var_type(char *type);
char *expression(program *expr, bool to_double, bool to_i32);
void declaration(program *node, bool global);
int charlit_to_int(char *string);
int intlit_to_int(char *string);
int size(char *type);
void print_tab(int local_indent);
void i32_to_double(char *value);
void i1_to_i32(char *value);
void i1_to_double(char *value);
void i32_to_i1(char *value);
void check_gen_while(program *node);
void check_gen_if(program *node);
void initialize_global_vars(void);
void insert_global_var(struct _s1 *node, char *var_name);
int check_true_false(char *value);