#include "semantics.h"
#include "structures.h"
#include "symbol_table.h"

#define STRING_SIZE 100

table * symtab = NULL;

void check_program(program * full_program){
    //criar global symbol table

    symtab = insert_table("Global");
    insert_default_functions();

    program * aux = full_program->children;

    while(aux){
        if(strcmp(aux->type, "Declaration") == 0){
            //adicionar a tabela de simbolos globais
            check_declaration(symtab, aux);
        }
        else if(strcmp(aux->type, "FuncDeclaration") == 0){
            //adicionar a tabela de simbolos globais
            check_func_declaration(aux);
        }
        else if(strcmp(aux->type, "FuncDefinition") == 0){
            check_func_definition(aux);
        } else{
            printf("\n\nERRO WTF IS GOING ON\n\n");
        }
        
        aux = aux->next;
        
    }
    
}

void insert_default_functions(void){
    //PUTCHAR
    func_parameter * parameter = (func_parameter *)malloc(sizeof(func_parameter));
    parameter->next = NULL;
    parameter->id = NULL;
    parameter->type = strdup("int");

    insert_function(symtab, strdup("putchar"), strdup("int"), parameter);

    //GETCHAR
    parameter = (func_parameter *)malloc(sizeof(func_parameter));
    parameter->next = NULL;
    parameter->id = NULL;
    parameter->type = strdup("void");

    insert_function(symtab, strdup("getchar"), strdup("void"), parameter);

}

void check_declaration(table * symtable, program * node){
    // uma declaraçao apenas
    //node é "Declaration"
    //node -> children é int/char/double/short
    //node -> children -> next é o ID

    if(!search_function(strdup(node->children->next->children->type), symtab)){
        //TODO ERRO -> variavel ja definida
        return;
    }

    table_element * inserted = insert_variable(symtable, strdup(node->children->next->children->type), strdup(node->children->type));

    if(! inserted) {
        //ERRO -> NAO DEVIA CHEGAR AQUI
        printf("\n\nNAO DEVIA CHEGAR AQUI\n\n");
    }

    //TODO Verificar se os tipos de dados dao match 
}

void check_func_declaration(program * node){
    //uma func declaration
    // node -> children é o tipo int/void/char ...
    // node -> children -> next é ID
    // node -> children -> next -> next é parameterList
    // node -> children -> next -> next -> children é o primeiro parametro
    // node -> children -> next -> next -> children -> children é o tipo do primeiro parametro
    
    if(!search_function(strdup(node->children->next->children->type), symtab)){
        //TODO ERRO -> variavel ja definida
        return;
    }

    program * aux = node -> children -> next -> next -> children;
    func_parameter * aux_params, * parameters;
    aux_params = parameters = (func_parameter *)malloc(sizeof(func_parameter));

    parameters->next = NULL;

    //Guardar Tipo
    parameters->type = strdup(aux->children->type);

    if(aux->children->next){
        //Tambem ha um ID para guardar
        parameters->id = strdup(aux->children->next->children->type);
    } else {
        //TODO VERIFICAÇAO DE TIPO / ERROS; ETC
        parameters->id = NULL;
    }

    aux = aux -> next;

    while(aux){
        aux_params->next = (func_parameter *)malloc(sizeof(func_parameter));
        aux_params = aux_params->next;

        aux_params->next = NULL;

        //Guardar Tipo
        parameters->type = strdup(aux->children->type);

        if(aux->children->next){
            //Tambem ha um ID para guardar
            aux_params->id = strdup(aux->children->next->children->type);
        } else {    
            //TODO VERIFICAÇAO DE TIPO / ERROS; ETC
            aux_params->id = NULL;
        }

        aux = aux -> next;
    }

    table_element * inserted = insert_function(symtab, strdup(node->children->next->children->type), strdup(node->children->type), parameters);

    if(! inserted) {
        //ERRO -> NAO DEVIA CHEGAR AQUI
        printf("\n\nNAO DEVIA CHEGAR AQUI\n\n");
    }
}

void check_func_definition(program * node){
    char string[STRING_SIZE];
    table * tab;
    //node -> children é o tipo int/void/char
    //node -> children -> next é ID
    //node -> children -> next -> next é paramList
    //node -> children -> next -> next -> next é body

    sprintf(string, "Function %s", node ->children->next->children->type);

    if(! (tab = insert_table(strdup(string)))){
        //ERRO, FUNÇAO JA FOI DEFINIDA
        return;
    }

    //INserior return e parametros
}