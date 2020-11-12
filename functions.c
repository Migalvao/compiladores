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
    
    if(strcmp(my_program->type, "Semi") != 0){    
        print_indent(indent);
        indent += 2;

        if(strcmp(my_program->type, "RealComma") == 0)
            printf("Comma\n");
        else
            printf("%s\n", my_program->type);

        if(my_program->children)
            print_ast(my_program->children);

        indent -= 2;

    }
    
    if(my_program->next)
        print_ast(my_program->next);
}

program * children_to_brother(program * no){
    if(strcmp(no->type, "Comma") == 0){
        program * aux, * next, * novos_irmaos;
        if(no->children){
            //temos de receber os irmaos desses filhos primeiro
            novos_irmaos = children_to_brother(no->children);

            aux = novos_irmaos;
            while(aux->next)
                aux = aux-> next;
                //se houver mais do que um novo irmao, para poder adicionar no fim

            //por os irmaos iniciais DEPOIS dos novos irmaos
            aux->next = no->next;
            //definir os novos irmaos como os iniciais
            no->next = novos_irmaos;
        }

        //desfazer o no atual e devolver os irmaos para cima
        next = no->next;
        free(no);
        return next;
    } else {
        if(strcmp(no->type, "RealComma") == 0)
            strcpy(no->type, "Comma");
        
        return no;
    }
}

void free_arvore(program * no){

    if(no->children)
        free_arvore(no->children);

    if(no->next)
        free_arvore(no->next);

    free(no);
}