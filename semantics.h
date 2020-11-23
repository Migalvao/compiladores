#include "structures.h"
#include "symbol_table.h"
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef enum {int_t, short_t, char_t, double_t, undefined_t, void_t} data_type;

void check_program(program * full_program);
void insert_default_functions(void);
void check_declaration(table * symtable, program * node);
void check_func_declaration(program * node);
void check_func_definition(program * node);
void check_func_body(table * tab, program * node);
void check_statement(table * tab, program * node);
data_type check_expression(table * tab, program * node);
data_type string_to_data_type(char * type);
char * data_type_to_string(data_type type);
data_type check_call(program * node);
data_type check_var(table * tab, program * node);
data_type check_not(table * tab, program * node);
data_type check_operation(table * tab, program * node);
data_type check_commas(table * tab, program * node);
