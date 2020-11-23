#include "semantics.h"
#include "structures.h"
#include "symbol_table.h"

#define STRING_SIZE 100

table * symtab = NULL;
char * aux_string;

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

    insert_function(symtab, strdup("getchar"), strdup("int"), parameter);

}

void check_declaration(table * symtable, program * node){
    // uma declaraçao apenas
    //node é "Declaration"
    //node -> children é int/char/double/short
    //node -> children -> next é o ID

    if(search_variable(strdup(node->children->next->children->type), symtab)){
        //TODO ERRO -> variavel ja definida
        return;
    }

    aux_string = strdup(node->children->type);
    * aux_string = tolower(* aux_string);   //passar de Int para int
    table_element * inserted = insert_variable(symtable, strdup(node->children->next->children->type), aux_string);

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
    
    if(search_function(strdup(node->children->next->children->type), symtab)){
        //TODO ERRO -> variavel ja definida
        return;
    }

    program * aux = node -> children -> next -> next -> children;
    func_parameter * aux_params, * parameters;
    aux_params = parameters = (func_parameter *)malloc(sizeof(func_parameter));

    parameters->next = NULL;
    
    //Guardar Tipo
    aux_string = strdup(aux->children->type);
    * aux_string = tolower(* aux_string);   //Passar Int para int
    parameters->type = aux_string;

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
        aux_string = strdup(aux->children->type);
        * aux_string = tolower(* aux_string);   //Passar Int para int
        aux_params->type = aux_string;

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
    program * aux;
    table_element * inserted;
    //node -> children é o tipo int/void/char
    //node -> children -> next é ID
    //node -> children -> next -> next é paramList
    //node -> children -> next -> next -> next é body

    sprintf(string, "Function %s", node ->children->next->children->type);
    
    aux_string = strdup(node->children->type);
    * aux_string = tolower(* aux_string);   //Passar Int para int

    if(! (tab = insert_table(strdup(string)))){
        //ERRO, FUNÇAO JA FOI DEFINIDA
        printf("Function %s already defined!", node ->children->next->children->type);
        return;
    }

    if(!search_function(strdup(node->children->next->children->type), symtab)){
        //O header ainda nao esta na tabela global
        check_func_declaration(node);
    }

    //Inserior return e parametros
    inserted = insert_variable(tab, strdup("return"), aux_string);
    
    aux = node -> children -> next -> next -> children;
    while(aux){
        if(aux->children->next){
            //temos um ID
            inserted = insert_variable(tab, strdup(aux->children->next->children->type), strdup(aux->children->type));
        }
        aux = aux -> next;
    }

    check_func_body(tab, node -> children -> next -> next -> next);
}

void check_func_body(table * tab, program * node){
    program * aux = node -> children;
    //node -> children, se existir sao as declarations and statemants
    
    while(aux){
        if(strcmp(aux->type, "Declaration") == 0){
            check_declaration(tab, aux);
        } else {
            check_statement(tab, aux);
        }

        aux = aux -> next;
    }
}

void check_statement(table * tab, program * node){
    if(strcmp(node->type, "If") == 0){
        //check_if();
    } else if(strcmp(node->type, "While") == 0){
        //check_while();
    } else if(strcmp(node->type, "Return") == 0){
        //check_return();
    } else if(strcmp(node->type, "StatList") == 0){
        //check_statlist();
    } else if(strcmp(node->type, "Erro") == 0){
        //ignorar erro
    } else{
        //em principio, expressions;
        //check_expression();
    }
}

data_type check_expression(table * tab, program * node){
    if(strcmp(node->type, "Call") == 0){
        //check_call() que vai retornar o tipo
    } else if(strcmp(node->type, "IntLit") == 0){
        return int_t;
    } else if(strcmp(node->type, "ChrLit") == 0){
        return char_t;
    } else if(strcmp(node->type, "RealLit") == 0){
        return double_t;
    } else if(strcmp(node->type, "Id") == 0){
        //search_variable e retornar o tipo
    } else if(strcmp(node->type, "Erro") == 0){
        //Ignorar erro
    } else if(strcmp(node->type, "Not") == 0){
        //check_not() que vai retornar o tipo
    } else if(strcmp(node->type, "Plus") == 0 || strcmp(node->type, "Minus") == 0){
        //check_not() que vai retornar o tipo
    } else if(strcmp(node->type, "Gt") == 0 ||
            strcmp(node->type, "Lt") == 0 ||
            strcmp(node->type, "Ge") == 0 ||
            strcmp(node->type, "Le") == 0 ||
            strcmp(node->type, "Ne") == 0 ||
            strcmp(node->type, "Eq") == 0 ||
            strcmp(node->type, "BitWiseXor") == 0 ||
            strcmp(node->type, "BitWiseOr") == 0 ||
            strcmp(node->type, "BitWiseAnd") == 0 ||
            strcmp(node->type, "And") == 0 ||
            strcmp(node->type, "Or") == 0 ||
            strcmp(node->type, "Mod") == 0 ||
            strcmp(node->type, "Div") == 0 ||
            strcmp(node->type, "Mul") == 0 ||
            strcmp(node->type, "Sub") == 0 ||
            strcmp(node->type, "Add") == 0 ||
            strcmp(node->type, "Store") == 0){
                //check_operation e retornar o tipo
            }
    else{
        //commas e afins
        //check_expression nos filhos, so isso
        
    }
}