#include <string.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "structures.h"
#include "symbol_table.h"
#include "functions.h"

int indent = 0;
extern int line, column;
extern char *yytext;
extern bool is_error;

program *insert_element(char *type, program *children)
{

    program *new = (program *)malloc(sizeof(program));
    new->next = NULL;
    new->type = strdup(type);
    new->annotation = NULL;
    if (strcmp(new->type, "Call") == 0)
    {
        new->line = children->line;
        new->column = children->column;
    }
    else
    {

        new->line = line;
        new->column = (int)(column - strlen(yytext));
    }

    new->children = children;

    //printf("type - %s\ncolumn - %d\nyytext - %ld\n", new->type, new -> column, strlen(yytext));

    return new;
}

void print_indent(int local_indent)
{
    for (int i = 0; i < local_indent; i++)
        printf(".");
}

void print_ast(program *my_program)
{

    print_indent(indent);
    indent += 2;

    if (strcmp(my_program->type, "IntLit") == 0)
    {
        printf("IntLit(%s)\n", my_program->children->type);
    }
    else if (strcmp(my_program->type, "ChrLit") == 0)
        printf("ChrLit(%s)\n", my_program->children->type);
    else if (strcmp(my_program->type, "RealLit") == 0)
        printf("RealLit(%s)\n", my_program->children->type);
    else if (strcmp(my_program->type, "Id") == 0)
        printf("Id(%s)\n", my_program->children->type);

    else if (strcmp(my_program->type, "RealComma") == 0)
    {
        printf("Comma\n");
        if (my_program->children)
            print_ast(my_program->children);
    }
    else
    {
        printf("%s\n", my_program->type);
        if (my_program->children)
            print_ast(my_program->children);
    }

    indent -= 2;

    if (my_program->next)
        print_ast(my_program->next);
}

program *children_to_brother(program *no)
{
    if (strcmp(no->type, "Comma") == 0)
    {
        program *aux, *next, *novos_irmaos;
        if (no->children)
        {
            //temos de receber os irmaos desses filhos primeiro
            novos_irmaos = children_to_brother(no->children);

            aux = novos_irmaos;
            while (aux->next)
                aux = aux->next;
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
    }
    else
    {
        if (strcmp(no->type, "RealComma") == 0)
            strcpy(no->type, "Comma");

        return no;
    }
}

void free_arvore(program *no)
{

    if (no->children)
        free_arvore(no->children);

    if (no->next)
        free_arvore(no->next);

    free(no);
}

void print_ast_noted(program *my_program)
{
    print_indent(indent);
    indent += 2;

    if (strcmp(my_program->type, "IntLit") == 0)
    {
        if (my_program->annotation)
            printf("IntLit(%s) - %s\n", my_program->children->type, my_program->annotation);
        else
            printf("IntLit(%s)\n", my_program->children->type);
    }

    else if (strcmp(my_program->type, "ChrLit") == 0)
    {
        if (my_program->annotation)
            printf("ChrLit(%s) - %s\n", my_program->children->type, my_program->annotation);
        else
            printf("ChrLit(%s)\n", my_program->children->type);
    }
    else if (strcmp(my_program->type, "RealLit") == 0)
    {
        if (my_program->annotation)
            printf("RealLit(%s) - %s\n", my_program->children->type, my_program->annotation);
        else
            printf("RealLit(%s)\n", my_program->children->type);
    }
    else if (strcmp(my_program->type, "Id") == 0)
    {
        if (my_program->annotation)
            printf("Id(%s) - %s\n", my_program->children->type, my_program->annotation);
        else
            printf("Id(%s)\n", my_program->children->type);
    }

    else if (strcmp(my_program->type, "RealComma") == 0)
    {
        if (my_program->annotation)
            printf("Comma - %s\n", my_program->annotation);
        else
            printf("Comma\n");
        if (my_program->children)
            print_ast_noted(my_program->children);
    }
    else
    {
        if (my_program->annotation)
            printf("%s - %s\n", my_program->type, my_program->annotation);
        else
            printf("%s\n", my_program->type);

        if (my_program->children)
            print_ast_noted(my_program->children);
    }

    indent -= 2;

    if (my_program->next)
        print_ast_noted(my_program->next);
}

void print_error(char *text, int l, int c)
{
    is_error = true;
    printf("Line %d, col %d: %s\n", l, c, text);
}