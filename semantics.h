#include "structures.h"
#include "symbol_table.h"
#include <stdio.h>
#include <string.h>

void insert_default_functions();
void check_program(program * myprogram);
void check_func_declaration(program * node);
void check_func_definition(program * node);