#include <string.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "structures.h"
#include "symbol_table.h"
#include "functions.h"
#include "gen_code.h"

void start_program(program * prog){
    program * my_program;
    if(strcmp(prog->type, "Program") == 0){
       my_program = prog->children;
    }
    else{
        my_program = prog;
    }
    
    while(my_program){
        printf("\n\nNEW FUNCTION\n\n");
        printf("%s\n", prog->type);

        if(strcmp(my_program->type, "IntLit") == 0){
            printf("i32 %s ", my_program->children->type);
        }
        else if(strcmp(my_program->type, "ChrLit") == 0){
            printf("i32 %s ", my_program->children->type);
        }
        else if(strcmp(my_program->type, "RealLit") == 0){
            printf("double %s ", my_program->children->type);
        }
        else if(strcmp(my_program->type, "Id") == 0){
            printf("Id(%s)\n", my_program->children->type);
        }

        //ACHO Q ISTO NAO VAI SER PRECISO
        /*else if(strcmp(my_program->type, "RealComma") == 0){
            printf(", ");
            if(my_program->children)
                print_ast_noted(my_program->children);
        }*/

        else{
            printf("                        %s\n", my_program->type);
            if(strcmp(my_program->type, "FuncDefinition") == 0){
                function_def(my_program);
            }
            else if(strcmp(my_program->type, "FuncDeclaration") == 0){
                function_dec(my_program);

            }

            /*if(my_program->children){
                ;
            }*/
        }
        printf("\n\nEND FUNCTION\n");
        my_program = my_program->next;
    }   
}

void function_def(program * node){
    //node - FuncDefinition
    //node->children - tipo de funcao
    //node->children->next - nome da funcao
    //node->children->next->next - se tem ou nao paramlist
    //node->children->next->next->next - func body

    //DEFINIÇAO DE FUNCAO
    program * param;

    printf("define ");
    //IF PARA SABER O TIPO DA FUNCAO!
    if(strcmp(node->children->type, "Int") == 0 || strcmp(node->children->type, "Char") == 0 || strcmp(node->children->type, "Short") == 0){
        printf("i32 ");
    }
    else if(strcmp(node->children->type, "Void") == 0){
        //nao sei ainda o q e suposto imprimir
        printf("void ");
    }
    //DOUBLE
    else{
        printf("double ");
    }

    printf("@%s(", node->children->next->type);

    if(strcmp(node->children->next->next->type, "ParamList") == 0){
        //printf("tem parametros\n");
        param = node->children->next->next->children;
        //Este if ve se existe parametros ou nao na funcao (node->children->next->next->children->children->type = tipo de parametro)
        if(strcmp(node->children->next->next->children->children->type, "Void") == 0){
            //printf("via");
            printf(") {\n");
        }
        else{
            while(param != NULL){
                printf("%s %s, ", var_type(param->children->type), param->children->next->type);
                param = param->next; 
            }
            printf(") {\n");
        }
    }

    //printf("FAUSTO  %s\n", node->children->next->next->next->type);
    function_body(node->children->next->next->next);
}

void function_dec(program * node){
    program * param;
    //DECLARAÇAO DE FUNCAO
    printf("define ");
    //IF PARA SABER O TIPO DA FUNCAO!
    if(strcmp(node->children->type, "Int") == 0 || strcmp(node->children->type, "Char") == 0 || strcmp(node->children->type, "Short") == 0){
        printf("i32 ");
    }
    else if(strcmp(node->children->type, "Void") == 0){
        //nao sei ainda o q e suposto imprimir
        printf("void ");
    }
    //DOUBLE
    else{
        printf("double ");
    }

    printf("@%s(", node->children->next->children->type);

    if(strcmp(node->children->next->next->type, "ParamList") == 0){
        //printf("tem parametros\n");
        param = node->children->next->next->children;
        //Este if ve se existe parametros ou nao na funcao (node->children->next->next->children->children->type = tipo de parametro)
        if(strcmp(node->children->next->next->children->children->type, "Void") == 0){
            //printf("via");
            printf(");\n");
        }
        else{
            while(param != NULL){
                printf("%s %s, ", var_type(param->children->type), param->children->next->type);
                param = param->next; 
            }
            printf(");\n");
        }
    }
}

void function_body(program * func_body){
    printf("BODY\n");
    program * body = func_body->children;

    while(body){
        //printf("RUBEN %s\n", body->type);
        body = body->next;
    }
}

char * var_type(char * type){
    //IF PARA SABER O TIPO DA FUNCAO!
    if(strcmp(type, "Int") == 0 || strcmp(type, "Char") == 0 || strcmp(type, "Short") == 0){
        return("i32");
    }
    else if(strcmp(type, "Void") == 0){
        //nao sei ainda o q e suposto imprimir
        return("void");
    }
    //DOUBLE
    else{
        return("double");
    }
}