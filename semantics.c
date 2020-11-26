#include "semantics.h"
#include "structures.h"
#include "functions.h"
#include "symbol_table.h"

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
    char string[STRING_SIZE];
    //node é "Declaration"
    //node -> children é int/char/double/short
    //node -> children -> next é o ID
    //node -> children -> next -> next é a expression, se houver

    if(search_variable(strdup(node->children->next->children->type), symtable)){
        sprintf(string, "Symbol %s already defined", node->children->next->children->type);
        print_error(string, node->children->next->line, node->children->next->column);
        return;
    } 

    aux_string = strdup(node->children->type);
    * aux_string = tolower(* aux_string);   //passar de Int para int
    table_element * inserted = insert_variable(symtable, strdup(node->children->next->children->type), aux_string, false);
    
    if(! inserted) {
        printf("\n\nNAO DEVIA CHEGAR AQUI\n\n");
    }

    //TODO Verificar se os tipos de dados dao match 
    if(node -> children -> next -> next){

        check_expression(symtable, node -> children -> next -> next);
    }
    
}

void check_func_declaration(program * node){
    //uma func declaration
    // node -> children é o tipo int/void/char ...
    // node -> children -> next é ID
    // node -> children -> next -> next é parameterList
    // node -> children -> next -> next -> children é o primeiro parametro
    // node -> children -> next -> next -> children -> children é o tipo do primeiro parametro
    
    if(search_function(node->children->next, symtab)){
        //TODO ERRO -> variavel ja definida
        return;
    }

    //-----------------------------------------------------------------------

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

    aux_string = strdup(node->children->type);
    * aux_string = tolower(* aux_string);   //Passar Int para int
    table_element * inserted = insert_function(symtab, strdup(node->children->next->children->type), aux_string, parameters);

    if(! inserted) {
        printf("\n\nNAO DEVIA CHEGAR AQUI FUNC\n\n");
    }
}

void check_func_definition(program * node){

    char string[STRING_SIZE];
    table * tab;
    program * aux;
    table_element * inserted;
    func_declaration * function;
    //node -> children é o tipo int/void/char
    //node -> children -> next é ID
    //node -> children -> next -> next é paramList
    //node -> children -> next -> next -> next é body
    
    sprintf(string, "Function %s", node ->children->next->children->type);

    if(! (tab = insert_table(strdup(string)))){
        //ERRO, FUNÇAO JA FOI DEFINIDA
        sprintf(string, "Symbol %s already defined", node ->children->next->children->type);
        print_error(string, node ->children->next->line, node ->children->next->column);
        //printf("Function %s already defined!", node ->children->next->children->type);
        return;
    }   

    if(!(function = search_function(node->children->next, symtab))){
        //O header ainda nao esta na tabela global
        check_func_declaration(node);
    }
    else{
        char help[STRING_SIZE * 2];
        char help2[STRING_SIZE];

        //VER SE O NUMERO DE PARAMETROS E IGUAL E SE OS PARAMETRO SAO OS MESMOS
        //function == NULL se nao forem iguais os parametros, function != NULL function vai ser igual a um node

        if(function){
            strcpy(help2, node->children->type);
            *help2 = tolower(*help2);
            if(strcmp(help2, function->type) != 0){
                sprintf(help, "Conflicting types (got %s, expected %s)", help2, function->type);
                print_error(help, node->children->line, node->children->column);
            }
        }

        /*
        //ERRO DE CONFLICTING TYPES
        while(param_aux1 != NULL){
            strcpy(help2, param_aux1->children->type);
            *help2 = tolower(*help2);
            if(strcmp(help2, param_aux2->type) != 0){
                sprintf(help, "Conflicting types (got %s, expected %s)", help2, param_aux2->type);
                print_error(help, node->children->line, node->children->column);
                break;
            }

            param_aux1 = param_aux1->next;
            param_aux2 = param_aux2->next;
        }
        */
    }

    aux_string = strdup(node->children->type);
    * aux_string = tolower(* aux_string);   //Passar Int para int

    //Inserior return e parametros
    inserted = insert_variable(tab, strdup("return"), aux_string, false);
    
    aux = node -> children -> next -> next -> children;
    while(aux){
        if(aux->children->next){
            //temos um ID
            aux_string = strdup(aux->children->type);
            * aux_string = tolower(* aux_string);   //Passar Int para int
            inserted = insert_variable(tab, strdup(aux->children->next->children->type), aux_string, true);
        }
        aux = aux -> next;
    }

    check_func_body(tab, node -> children -> next -> next -> next, node->children->type);
}

void check_func_body(table * tab, program * node, char * func_type){
    program * aux = node -> children;
    //node -> children, se existir sao as declarations and statemants

    while(aux){
        if(strcmp(aux->type, "Declaration") == 0){
            check_declaration(tab, aux);
        } else {
            check_statement(tab, aux, func_type);
        }

        aux = aux -> next;
    }
}

void check_statement(table * tab, program * node, char * func_type){
    if(strcmp(node->type, "If") == 0){
        check_if(tab, node, func_type);
    } else if(strcmp(node->type, "While") == 0){
        check_while(tab, node, func_type);
    } else if(strcmp(node->type, "Return") == 0){
        check_return(tab, node, func_type);
    } else if(strcmp(node->type, "StatList") == 0){
        check_statlist(tab, node, func_type);
    } else if(strcmp(node->type, "Erro") == 0){
        //ignorar erro
    } else{
        //em principio, expressions;
        check_expression(tab, node);
    }
}

void check_if(table * tab, program * node, char * func_type){
    program * stat;
    //FALTAM VERIFICAÇOES!

    program *expr = node->children;
    check_expression(tab, expr);
    
    if(node->children->next){
        stat = node->children->next;
    
        check_statement(tab, stat, func_type);
    }

    if(node->children->next->next){
        stat = node->children->next->next;

        check_statement(tab, stat, func_type);
    }
}

void check_while(table * tab, program * node, char * func_type){
    //FALTAM VERIFICAÇOES!

    program *expr = node->children;

    check_expression(tab, expr);
    
    if(node->children->next){
        program *stat = node->children->next;
        
        check_statement(tab, stat, func_type);
    
    }
}

void check_return(table * tab, program * node, char * func_type){
    //FALTAM VERIFICAÇOES!
    //verificar se existe erro invalid use of void
    if((strcmp(func_type, "Void") == 0) && strcmp(node->children->type, "Null") != 0){
        print_error("Invalid use of void type in declaration", node->children->line, node->children->column);
    }

    if(node->children){
        program *expr = node->children;
        check_expression(tab, expr);
    }
}

void check_statlist(table * tab, program * node, char * func_type){
    //FALTAM VERIFICAÇOES!

    program *stat_list = node->children;
    
    while(stat_list){
        check_statement(tab, stat_list, func_type);
        stat_list = stat_list -> next;
    }
}

data_type check_expression(table * tab, program * node){
    if(strcmp(node->type, "Call") == 0){
        return check_call(tab, node);   

    } else if(strcmp(node->type, "IntLit") == 0){
        return int_t;

    } else if(strcmp(node->type, "ChrLit") == 0){
        return int_t;

    } else if(strcmp(node->type, "RealLit") == 0){
        return double_t;

    } else if(strcmp(node->type, "Id") == 0){
        return check_var(tab, node);

    } else if(strcmp(node->type, "Erro") == 0){
        //Ignorar erro
        return undefined_t;

    } else if(strcmp(node->type, "Not") == 0){
        return check_not(tab, node);
    } else if(strcmp(node->type, "Plus") == 0 || strcmp(node->type, "Minus") == 0){
        return check_not(tab, node);
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
                return check_operation(tab, node);
            }
    else if(strcmp(node->type, "Null") == 0){
        node->type = strdup("Null - void");
        return void_t;
    }
    else{
        return check_commas(tab, node);
    }
}

data_type check_not(table * tab, program * node){
    //FALTAM VERIFICAÇOES!

    program *expr = node->children;

    data_type type = check_expression(tab, expr);

    char help[STRING_SIZE];

    if(type == void_t || type == undefined_t){
        sprintf(help, "Operator %s cannot be applied to type %s", string_to_operator(node->type), data_type_to_string(type));

        print_error(help, node->line, node->column);

        sprintf(help, "%s - undef", node->type);
        node->type = strdup(help);

        return undefined_t;
    }
    else{
        sprintf(help, "%s - %s", node->type, data_type_to_string(type));
        node->type = strdup(help);

        return type;
    }
}

data_type check_operation(table * tab, program * node){
    program * child1 = node->children;
    program * child2 = node->children->next;

    data_type type_child1 = check_expression(tab, child1);
    data_type type_child2 = check_expression(tab, child2);

    char help[STRING_SIZE];

    if(type_child1 == void_t || type_child2 == void_t || type_child1 == undefined_t || type_child2 == undefined_t){
            //printf("%s - %s\n", node->type, string_to_operator(node->type));
            sprintf(help, "Operator %s cannot be applied to types %s, %s", string_to_operator(node->type), data_type_to_string(type_child1), data_type_to_string(type_child2));

            print_error(help, node->line, node->column);

            sprintf(help, "%s - undef", node->type);
            node->type = strdup(help);

            return undefined_t;
    }

    else if(type_child1 == double_t || type_child2 == double_t){
        if(strcmp(node->type, "Store") == 0){
            sprintf(help, "%s - %s", node->type, data_type_to_string(type_child1));
            node->type = strdup(help);

            return type_child1;
        }
        else{
            sprintf(help, "%s - %s", node->type, data_type_to_string(double_t));
            node->type = strdup(help);

            return double_t;
        }
    }
    else if(type_child1 == int_t || type_child2 == int_t){
        if(strcmp(node->type, "Store") == 0){
            sprintf(help, "%s - %s", node->type, data_type_to_string(type_child1));
            node->type = strdup(help);

            return type_child1;
        }
        else{
            sprintf(help, "%s - %s", node->type, data_type_to_string(int_t));
            node->type = strdup(help);

            return int_t;
        }
    }
    else if(type_child1 == short_t || type_child2 == short_t){
        if(strcmp(node->type, "Store") == 0){
            sprintf(help, "%s - %s", node->type, data_type_to_string(type_child1));
            node->type = strdup(help);

            return type_child1;
        }
        else{
            sprintf(help, "%s - %s", node->type, data_type_to_string(short_t));
            node->type = strdup(help);

            return short_t;
        }
    }
    else{    
        //char 
        sprintf(help, "%s - %s", node->type, data_type_to_string(type_child1));
        node->type = strdup(help);

        return type_child1;
    }
}

data_type check_commas(table * tab, program * node){
    //PODE ESTAR INCOMPLETO OU INCORRETO!

    program * child1 = node->children;
    program * child2 = node->children->next;

    data_type type_child1 = check_expression(tab, child1);
    data_type type_child2 = check_expression(tab, child2);

    char help[STRING_SIZE];

    if(type_child1 == void_t || type_child2 == void_t || type_child1 == undefined_t || type_child2 == undefined_t){
            sprintf(help, "Operator , cannot be applied to types %s, %s", data_type_to_string(type_child1), data_type_to_string(type_child2));

            print_error(help, node->line, node->column);

            sprintf(help, "Comma - undef");
            node->type = strdup(help);

            return undefined_t;
    }

    else if(type_child1 == double_t || type_child2 == double_t){

        sprintf(help, "Comma - %s", data_type_to_string(double_t));
        node->type = strdup(help);

        return double_t;
    }
    else if(type_child1 == int_t || type_child2 == int_t){

            sprintf(help, "Comma - %s", data_type_to_string(int_t));
            node->type = strdup(help);

            return int_t;
    }
    else if(type_child1 == short_t || type_child2 == short_t){
        sprintf(help, "Comma - %s", data_type_to_string(short_t));
        node->type = strdup(help);

        return short_t;

    }
    else{    
        //char 
        sprintf(help, "Comma - %s", data_type_to_string(type_child1));
        node->type = strdup(help);

        return type_child1;
    }
}


char * data_type_to_string(data_type type){
    if(type == int_t){
        return strdup("int");
    } else if(type == char_t){
        return strdup("char");
    } else if(type == short_t){
        return strdup("short");
    } else if(type == double_t){
        return strdup("double");
    } else if(type == void_t){
        return strdup("void");
    } else if(type == undefined_t){
        return strdup("undef");
    } else{
        printf("\n\nERRO, N DEVIA ACONTECER\n\n");
        return NULL;
    }
}

data_type check_call(table * tab, program * node){
    char help[STRING_SIZE], help2[STRING_SIZE * 2];
    func_declaration * function;
    func_parameter * param;
    program * aux_node;
    data_type type;
    int i_param = 0, e_param = 0;
    //node -> type é "Call"
    //node -> children é o ID
    //node -> children -> next sao os parametros

    //procurar no global scope, so ai e que ha funçoes
    function = search_function(node->children, symtab);

    if(! function){
        sprintf(help, "Symbol %s is not a function", node->children->children->type);
        print_error(help, node->children->line, node->children->column);
        node -> type = strdup("Call - undef");
        return undefined_t;
    }

    //reescrever "Call"
    sprintf(help, "Call - %s", function->type);
    node -> type = strdup(help);

    //reescrever ID - precisamos do ID, o return value e os tipos dos parametros
    param = function->parameters;
    strcpy(help, param->type);
    
    param = param -> next;
    while(param != NULL){
        strcat(help, ",");
        strcat(help, param->type);
        param = param -> next;
    }
    
    sprintf(help2, "Id(%s) - %s(%s)", node->children->children->type, function->type, help);
    node->children->type = strdup(help2);
    
    //verificar parametros
    aux_node = node -> children -> next;        //parametros do input
    param = function->parameters;               //parâmetros da funçao(esperados)

    if(strcmp(param->type, "void") != 0)
        e_param++;
    param = param -> next;

    //TODO verificar tipos do parametro
    if(aux_node){
        type = check_expression(tab, aux_node);

        if(strcmp(aux_node->type, "Id") == 0){
            //parametro é um ID
            sprintf(help, "Id(%s) - %s", aux_node->children->type, data_type_to_string(type));
            aux_node->type = strdup(help);
            free(aux_node->children);
            aux_node->children = NULL;
        } 
        
        aux_node = aux_node -> next;
        i_param++;
    } 

    while(param != NULL && aux_node != NULL){
        //TODO verificar tipos do parametro
        type = check_expression(tab, aux_node);

        if(strcmp(aux_node->type, "Id") == 0){
            //parametro é um ID
            sprintf(help, "Id(%s) - %s", aux_node->children->type, data_type_to_string(type));
            aux_node->type = strdup(help);
            free(aux_node->children);
            aux_node->children = NULL;
        } 

        param = param -> next;
        e_param++;
        aux_node = aux_node -> next;
        i_param++;
    }

    if(param || aux_node){
        //ou temos parametros a mais ou parametros a menos
        if(param){
            while(param){
                param = param ->next;
                e_param++;
            }
        } else if(aux_node){
            while(aux_node){
                aux_node = aux_node ->next;
                i_param++;
            }
        }
    }

    //TODO verificar se o numero de parametros esta certo
    if(e_param != i_param){
        sprintf(help2, "Wrong number of arguments to function %s (got %d , required %d)", node->children->children->type, i_param, e_param);
        print_error(help2, node->children->line, node->children->column);
    }

    free(node->children->children);
    node->children->children = NULL;

    return string_to_data_type(function -> type);
}

data_type check_var(table * tab, program * node){
    char help[STRING_SIZE];
    var_declaration * variable;
    //node é o ID

    //procurar no local scope
    variable = search_variable(node->children->type, tab);

    if(!variable){
        //procurar no global scope
        variable = search_variable(node->children->type, symtab);
    }

    if(!variable){
        sprintf(help, "Unknown symbol %s", node->children->type);
        print_error(help, node->children->line, node->children->column);

        sprintf(help, "Id(%s) - undef", node->children->type);
        free(node->children);
        node->children = NULL;
        node->type = strdup(help);
        return undefined_t;
    }

    sprintf(help, "Id(%s) - %s", node->children->type, variable->type);
    free(node->children);
    node->children = NULL;
    node->type = strdup(help);

    return string_to_data_type(variable -> type);
}

data_type string_to_data_type(char * type){
    if(strcmp(type, "int") == 0)
        return int_t;
    else if(strcmp(type, "short") == 0)
        return short_t;
    else if(strcmp(type, "double") == 0)
        return double_t;
    else if(strcmp(type, "char") == 0)
        return char_t;
    else if(strcmp(type, "void") == 0)
        return void_t;
    else{
        printf("\n\nERRO, N DEVIA ACONTECER\n\n");
        return undefined_t;
    }
}

char * string_to_operator(char * str){
    if(strcmp(str, "Add") == 0 || strcmp(str, "Plus") == 0){
        return strdup("+");
    }
    else if(strcmp(str, "Store") == 0){
        return strdup("=");
    }
    else if(strcmp(str, "Sub") == 0 || strcmp(str, "Minus") == 0){
        return strdup("-");
    }
    else if(strcmp(str, "Mul") == 0){
        return strdup("*");
    }
    else if(strcmp(str, "Div") == 0){
        return strdup("/");
    }
    else if(strcmp(str, "Mod") == 0){
        return strdup("%");
    }
    else if(strcmp(str, "Or") == 0){
        return strdup("||");
    }
    else if(strcmp(str, "And") == 0){
        return strdup("&&");
    }
    else if(strcmp(str, "BitWiseAnd") == 0){
        return strdup("&");
    }
    else if(strcmp(str, "BitWiseOr") == 0){
        return strdup("|");
    }
    else if(strcmp(str, "BitWiseXor") == 0){
        return strdup("^");
    }
    else if(strcmp(str, "Eq") == 0){
        return strdup("==");
    }
    else if(strcmp(str, "Ne") == 0){
        return strdup("!=");
    }
    else if(strcmp(str, "Le") == 0){
        return strdup("<=");
    }
    else if(strcmp(str, "Ge") == 0){
        return strdup(">=");
    }
    else if(strcmp(str, "Lt") == 0){
        return strdup("<");
    }
    else if(strcmp(str, "Gt") == 0){
        return strdup(">");
    }
    else if(strcmp(str, "Not") == 0){
        return strdup("!");
    }
    else if(strcmp(str, "RealComma") == 0){
        return strdup(",");
    }
    else if(strcmp(str, "Comma") == 0){
        return strdup(",");
    } 
    return NULL;
}