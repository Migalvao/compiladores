#include "structures.h"

program * insert_element(char * type,  program * children);
void print_indent(int local_indent);
void print_ast(program * my_program);
program * children_to_brother(program * no);
void free_arvore(program * no);
void print_ast_noted(program * my_program);