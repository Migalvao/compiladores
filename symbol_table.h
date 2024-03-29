#include <stdbool.h>
#include "structures.h"
#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

typedef struct _t4
{
    char *id;
    char *type; //int, double ou char
    struct _t4 *next;
} func_parameter;

typedef struct _t3
{
    char *id;
    char *type;                 //int, double ou char
    func_parameter *parameters; //"int, int, int"
} func_declaration;

typedef struct _t2
{
    bool is_param;
    char *id;
    char *type; //int, double ou char
} var_declaration;

typedef enum
{
    var_dec,
    func_dec
} table_element_type;

typedef struct _t1
{
    //um elemento de uma tabela
    table_element_type type;

    union
    {
        var_declaration *var;
        func_declaration *func;
    } entry_type;

    struct _t1 *next;

} table_element;

typedef struct _t0
{
    //Tabela em si
    char *name; //Global ou Function main ou wtv

    table_element *element; //primeira entry da tabela

    struct _t0 *next;
} table;

table_element *insert_function(table *tab, char *id, char *type, func_parameter *param);
table_element *insert_variable(table *tab, char *id, char *type, bool is_param);
table *insert_table(char *name);
var_declaration *search_variable(char *id, table *tab);
func_declaration *search_function(program *id_node, table *tab);
void print_tables();
void function_declarator(char *help, char *help2, func_parameter *param, char *type);
table *search_table(char *name);
void remove_variable(var_declaration *var);

#endif
