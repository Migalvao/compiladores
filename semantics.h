#include "structures.h"
#include "symbol_table.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void check_program(program * full_program);
void insert_default_functions(void);
void check_declaration(table * symtable, program * node);
void check_func_declaration(program * node);
void check_func_definition(program * node);