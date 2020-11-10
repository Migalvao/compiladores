#include <string.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "structures.h"
#include "functions.h"

int indent = 0;

program * insert_element(char * type,  program * children){

    program * new = (program *) malloc(sizeof(program));
    new->next = NULL;
    new->type = strdup(type);
    new->children = children;

    return new;
}

void print_indent(int local_indent){
    
    for(int i = 0; i < local_indent; i++)
    printf(".");
}

void print_ast(program * my_program){
    program * children = my_program->children;
    
    print_indent(indent);
    indent += 2;

    printf("%s\n", my_program->type);

    while(children){
        print_ast(children);
        children = children -> next;
    }

    indent -= 2;

    if(my_program->next)
        print_ast(my_program->next);
}

void print_no(program * no){
    program * aux = no;

    printf("\nTipo");
}