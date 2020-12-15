#include "structures.h"
#include "symbol_table.h"
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define STRING_SIZE 100

typedef enum
{
    int_t,
    short_t,
    char_t,
    double_t,
    undefined_t,
    void_t,
    function_t
} data_type;

void check_program(program *full_program);
void insert_default_functions(void);
void check_declaration(table *symtable, program *node);
func_declaration *check_func_declaration(program *node);
void check_func_definition(program *node);
void check_func_body(table *tab, program *node, char *func_type);
void check_statement(table *tab, program *node, char *func_type);
data_type check_expression(table *tab, program *node);
data_type string_to_data_type(char *type);
char *data_type_to_string(data_type type);
data_type check_call(table *tab, program *node);
data_type check_var(table *tab, program *node);
data_type check_not(table *tab, program *node);
data_type check_binary_operation(table *tab, program *node);
data_type check_operation(table *tab, program *node);
data_type check_commas(table *tab, program *node);
data_type check_comparison(table *tab, program *node);
void check_while(table *tab, program *node, char *func_type);
void check_if(table *tab, program *node, char *func_type);
void check_return(table *tab, program *node, char *func_type);
void check_statlist(table *tab, program *node, char *func_type);
//data_type check_expression(table * tab, program * node);
char *string_to_operator(char *str);
int compare_types(char *first, char *second);
bool check_function_type(char *help, char *help2, program *node, data_type type1, data_type type2);