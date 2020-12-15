#include "semantics.h"
#include "structures.h"
#include "functions.h"
#include "symbol_table.h"

table *symtab = NULL;
char *aux_string, function[STRING_SIZE];

void check_program(program *full_program)
{
    //criar global symbol table
    symtab = insert_table("Global");
    insert_default_functions();

    program *aux = full_program->children;

    while (aux)
    {
        if (strcmp(aux->type, "Declaration") == 0)
        {
            //adicionar a tabela de simbolos globais
            check_declaration(symtab, aux);
        }
        else if (strcmp(aux->type, "FuncDeclaration") == 0)
        {
            //adicionar a tabela de simbolos globais
            check_func_declaration(aux);
        }
        else if (strcmp(aux->type, "FuncDefinition") == 0)
        {
            check_func_definition(aux);
        }
        else
        {
            printf("\n\nERRO WTF IS GOING ON\n\n");
        }
        aux = aux->next;
    }
}

void insert_default_functions(void)
{
    //PUTCHAR
    func_parameter *parameter = (func_parameter *)malloc(sizeof(func_parameter));
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

void check_declaration(table *symtable, program *node)
{
    char string[3 * STRING_SIZE], aux[STRING_SIZE];
    var_declaration *var;
    data_type type;
    //node é "Declaration"
    //node -> children é int/char/double/short
    //node -> children -> next é o ID
    //node -> children -> next -> next é a expression, se houver

    aux_string = strdup(node->children->type);
    *aux_string = tolower(*aux_string); //passar de Int para int

    //ERRO INVALID USE OF VOID
    if (strcmp(node->children->type, "Void") == 0)
    {
        if (node->children->next->next)
            check_expression(symtable, node->children->next->next);
        print_error("Invalid use of void type in declaration", node->children->next->line, node->children->next->column);

        if (search_function(node->children->next, symtab))
        {
            sprintf(string, "Symbol %s already defined", node->children->next->children->type);
            print_error(string, node->children->next->line, node->children->next->column);
        }

        return;
    }

    if ((var = search_variable(strdup(node->children->next->children->type), symtable)))
    {
        strcpy(aux, node->children->type);
        *aux = tolower(*aux);

        if (node->children->next->next)
        {
            type = check_expression(symtable, node->children->next->next);

            if (compare_types(data_type_to_string(type), aux_string) == 1 && type != undefined_t)
            {
                sprintf(string, "Conflicting types (got %s, expected %s)", data_type_to_string(type), aux_string);
                print_error(string, node->children->next->line, node->children->next->column);
            }
        }

        if (symtable == symtab && compare_types(var->type, aux) == 1)
        {
            sprintf(string, "Conflicting types (got %s, expected %s)", aux, var->type);
            print_error(string, node->children->next->line, node->children->next->column);
        }
        else if (symtable != symtab)
        {
            sprintf(string, "Symbol %s already defined", node->children->next->children->type);
            print_error(string, node->children->next->line, node->children->next->column);
        }

        return;
    }

    //TODO Verificar se os tipos de dados dao match
    if (node->children->next->next)
    {

        type = check_expression(symtable, node->children->next->next);

        if (compare_types(data_type_to_string(type), aux_string) == 1 && type != undefined_t)
        {
            sprintf(string, "Conflicting types (got %s, expected %s)", data_type_to_string(type), aux_string);
            print_error(string, node->children->next->line, node->children->next->column);
        }
    }

    table_element *inserted = insert_variable(symtable, strdup(node->children->next->children->type), aux_string, false);

    if (!inserted)
    {
        printf("\n\nNAO DEVIA CHEGAR AQUI\n\n");
    }
}

//FUNCAO PARA VER ERRO INVALID USE OF VOID TYPE
int check_void(program *param_list)
{
    bool check = false;
    int count = 1;
    program *current = param_list->children;
    char string[STRING_SIZE];

    while (current)
    {
        if (strcmp(current->children->type, "Void") == 0 || check == true)
        {
            check = true;
            //Se houver um ID
            if (current->children->next)
            {
                sprintf(string, "Invalid use of void type in declaration");
                if (strcmp(current->children->type, "Void") == 0 && strcmp(param_list->children->children->type, "Void") != 0)
                {
                    print_error(string, current->children->line, current->children->column);
                }
                else
                {
                    print_error(string, param_list->children->children->line, param_list->children->children->column);
                }
                return 1; //vai dar erro
            }
            if (count >= 2)
            {
                sprintf(string, "Invalid use of void type in declaration");
                if (strcmp(current->children->type, "Void") == 0 && strcmp(param_list->children->children->type, "Void") != 0)
                {
                    print_error(string, current->children->line, current->children->column);
                }
                else
                {
                    print_error(string, param_list->children->children->line, param_list->children->children->column);
                }
                //print_error(string, current->children->line, current->children->column);
                return 1; //vai dar erro
            }
        }
        count++;
        current = current->next;
    }
    return 0; //nao vai dar erro
}

func_declaration *check_func_declaration(program *node)
{
    //uma func declaration
    // node -> children é o tipo int/void/char ...
    // node -> children -> next é ID
    // node -> children -> next -> next é parameterList
    // node -> children -> next -> next -> children é o primeiro parametro
    // node -> children -> next -> next -> children -> children é o tipo do primeiro parametro
    table *tab;
    char string[4 * STRING_SIZE], help1[STRING_SIZE], help2[STRING_SIZE], help3[STRING_SIZE];
    program *aux = node->children->next->next->children;
    func_declaration *func;
    func_parameter *aux_params, *parameters, *aux_params2;
    var_declaration *var;

    //TESTE PARA VER SE EXISTE ERRO DE INVALIDE USE OF VOID
    if (check_void(node->children->next->next) == 1)
    {
        //HA ERRO
        return NULL;
    }

    if ((func = search_function(node->children->next, symtab)))
    {
        //verificar se parametros e return batem certo
        function_declarator(help1, help2, func->parameters, func->type); //esperado

        aux_params = parameters = (func_parameter *)malloc(sizeof(func_parameter));

        parameters->next = NULL;

        strcpy(help3, node->children->type);
        *help3 = tolower(*help3); //Passar Int para int
        strcat(help3, "(");

        aux_string = strdup(aux->children->type);
        *aux_string = tolower(*aux_string); //Passar Int para int

        strcat(help3, aux_string);
        aux = aux->next;

        while (aux)
        {
            aux_string = strdup(aux->children->type);
            *aux_string = tolower(*aux_string); //Passar Int para int

            strcat(help3, ",");
            strcat(help3, aux_string);

            aux_params->next = (func_parameter *)malloc(sizeof(func_parameter));
            aux_params = aux_params->next;

            aux_params->next = NULL;
            aux_params->type = aux_string;

            if (aux->children->next)
            {
                //Tambem ha um ID para guardar
                aux_params->id = strdup(aux->children->next->children->type);
                aux_params2 = parameters;
                while (aux_params2->next)
                {
                    if (aux_params2->id && strcmp(aux_params2->id, aux_params->id) == 0)
                    {
                        //ID igual, mesmo nome de parametro
                        sprintf(string, "Symbol %s already defined", aux_params2->id);
                        print_error(string, aux->children->next->children->line, aux->children->next->children->column);
                        break;
                    }
                    aux_params2 = aux_params2->next;
                }
            }
            else
            {
                //TODO VERIFICAÇAO DE TIPO / ERROS; ETC
                aux_params->id = NULL;
            }

            aux = aux->next;
        }

        strcat(help3, ")");

        //verificar se dao match
        if (strcmp(help2, help3) != 0)
        {
            sprintf(string, "Conflicting types (got %s, expected %s)", help3, help2);
            print_error(string, node->children->next->line, node->children->next->column);
        }

        return NULL;
    }

    var = search_variable(node->children->next->children->type, symtab);
    if (var)
    {
        remove_variable(var);
    }
    sprintf(string, "Function %s", node->children->next->children->type);

    if (!(tab = insert_table(strdup(string))))
    {
        //JA TINHA SIDO DECLARADA, ERRO?
        printf("\n\nNAO DEVIA ENTRAR AQUI FUNC DECL\n\n");
    }

    //-----------------------------------------------------------------------

    aux = node->children->next->next->children;
    aux_params = parameters = (func_parameter *)malloc(sizeof(func_parameter));

    parameters->next = NULL;

    //Guardar Tipo
    aux_string = strdup(aux->children->type);
    *aux_string = tolower(*aux_string); //Passar Int para int
    parameters->type = aux_string;

    if (aux->children->next)
    {
        //Tambem ha um ID para guardar
        parameters->id = strdup(aux->children->next->children->type);
    }
    else
    {
        //TODO VERIFICAÇAO DE TIPO / ERROS; ETC
        parameters->id = NULL;
    }

    aux = aux->next;

    while (aux)
    {
        aux_params->next = (func_parameter *)malloc(sizeof(func_parameter));
        aux_params = aux_params->next;

        aux_params->next = NULL;

        //Guardar Tipo
        aux_string = strdup(aux->children->type);
        *aux_string = tolower(*aux_string); //Passar Int para int
        aux_params->type = aux_string;

        if (aux->children->next)
        {
            //Tambem ha um ID para guardar
            aux_params->id = strdup(aux->children->next->children->type);
            aux_params2 = parameters;
            while (aux_params2->next)
            {
                if (aux_params2->id && strcmp(aux_params2->id, aux_params->id) == 0)
                {
                    //ID igual, mesmo nome de parametro
                    sprintf(string, "Symbol %s already defined", aux_params2->id);
                    print_error(string, aux->children->next->children->line, aux->children->next->children->column);
                    break;
                }
                aux_params2 = aux_params2->next;
            }
        }
        else
        {
            //TODO VERIFICAÇAO DE TIPO / ERROS; ETC
            aux_params->id = NULL;
        }

        aux = aux->next;
    }

    aux_string = strdup(node->children->type);
    *aux_string = tolower(*aux_string); //Passar Int para int
    table_element *inserted = insert_function(symtab, strdup(node->children->next->children->type), aux_string, parameters);

    if (!inserted)
    {
        printf("\n\nNAO DEVIA CHEGAR AQUI FUNC\n\n");
    }
    return inserted->entry_type.func;
}

void check_func_definition(program *node)
{

    char string[4 * STRING_SIZE], help[STRING_SIZE * 2], help1[STRING_SIZE], help2[STRING_SIZE], help3[STRING_SIZE];
    table *tab;
    program *aux = node->children->next->next->children;
    func_parameter *params;
    table_element *inserted;
    func_declaration *function;
    bool already_checked = false, error = false;
    var_declaration *var;
    //node -> children é o tipo int/void/char
    //node -> children -> next é ID
    //node -> children -> next -> next é paramList
    //node -> children -> next -> next -> next é body

    sprintf(string, "Function %s", node->children->next->children->type);

    //TESTE PARA VER SE EXISTE ERRO DE INVALIDE USE OF VOID
    if (check_void(node->children->next->next) == 1)
    {
        //HA ERRO
        return;
    }

    if (!(function = search_function(node->children->next, symtab)))
    {
        var = search_variable(node->children->next->children->type, symtab);
        if (var)
        {
            remove_variable(var);
        }
        //O header ainda nao esta na tabela global
        function = check_func_declaration(node);
        already_checked = true;

        tab = search_table(string);
    }
    else
    {
        //verificar se parametros e return batem certo
        function_declarator(help1, help2, function->parameters, function->type); //esperado

        strcpy(help3, node->children->type);
        *help3 = tolower(*help3); //Passar Int para int
        strcat(help3, "(");

        aux_string = strdup(aux->children->type);
        *aux_string = tolower(*aux_string); //Passar Int para int

        strcat(help3, aux_string);
        aux = aux->next;

        while (aux)
        {
            aux_string = strdup(aux->children->type);
            *aux_string = tolower(*aux_string); //Passar Int para int

            strcat(help3, ",");
            strcat(help3, aux_string);

            aux = aux->next;
        }

        strcat(help3, ")");

        sprintf(string, "Function %s", node->children->next->children->type);

        tab = search_table(string);
        if (tab->element)
        {
            //ERRO, FUNÇAO JA FOI DEFINIDA
            sprintf(string, "Symbol %s already defined", node->children->next->children->type);
            print_error(string, node->children->next->line, node->children->next->column);
            //printf("Function %s already defined!", node ->children->next->children->type);
            return;
        }
        else
        {
            //verificar se dao match
            if (strcmp(help2, help3) != 0)
            {
                sprintf(string, "Conflicting types (got %s, expected %s)", help3, help2);
                print_error(string, node->children->next->line, node->children->next->column);
                return;
            }
        }

        //VER SE O NUMERO DE PARAMETROS E IGUAL E SE OS PARAMETRO SAO OS MESMOS
        //function == NULL se nao forem iguais os parametros, function != NULL function vai ser igual a um node

        if (function)
        {
            strcpy(help2, node->children->type);
            *help2 = tolower(*help2);
            if (strcmp(help2, function->type) != 0)
            {
                sprintf(help, "Conflicting types (got %s, expected %s)", help2, function->type);
                print_error(help, node->children->line, node->children->column);
            }
        }

        //ERRO DE CONFLICTING TYPES (A FUNÇAO E DE UM TIPO MAS O RETURN DA FUNÇAO E DE OUTRO TIPO)
        char *func_type;
        func_type = strdup(node->children->type);
    }

    aux_string = strdup(node->children->type);
    *aux_string = tolower(*aux_string); //Passar Int para int

    //Inserior return e parametros
    inserted = insert_variable(tab, strdup("return"), aux_string, false);

    aux = node->children->next->next->children;

    int i = 0, j;
    while (aux)
    {
        i++;
        if (aux->children->next)
        {
            //temos um ID
            aux_string = strdup(aux->children->type);
            *aux_string = tolower(*aux_string); //Passar Int para int

            j = 1;
            params = function->parameters;
            error = false;
            while (params->next && j < i)
            {
                j++;
                if (params->id && strcmp(params->id, aux->children->next->children->type) == 0)
                {
                    error = true;
                    //ID igual, mesmo nome de parametro
                    if (!already_checked)
                    {
                        sprintf(string, "Symbol %s already defined", params->id);
                        print_error(string, aux->children->next->children->line, aux->children->next->children->column);
                        break;
                    }
                }

                params = params->next;
            }

            if (!error)
                inserted = insert_variable(tab, strdup(aux->children->next->children->type), aux_string, true);
        }
        aux = aux->next;
    }

    check_func_body(tab, node->children->next->next->next, node->children->type);
}

void check_func_body(table *tab, program *node, char *func_type)
{
    program *aux = node->children;
    //node -> children, se existir sao as declarations and statemants

    while (aux)
    {
        if (strcmp(aux->type, "Declaration") == 0)
        {
            check_declaration(tab, aux);
        }
        else
        {
            check_statement(tab, aux, func_type);
        }

        aux = aux->next;
    }
}

void check_statement(table *tab, program *node, char *func_type)
{
    if (strcmp(node->type, "If") == 0)
    {
        check_if(tab, node, func_type);
    }
    else if (strcmp(node->type, "While") == 0)
    {
        check_while(tab, node, func_type);
    }
    else if (strcmp(node->type, "Return") == 0)
    {
        check_return(tab, node, func_type);
    }
    else if (strcmp(node->type, "StatList") == 0)
    {
        check_statlist(tab, node, func_type);
    }
    else if (strcmp(node->type, "Erro") == 0)
    {
        //ignorar erro
    }
    else
    {
        //em principio, expressions;
        check_expression(tab, node);
    }
}

void check_if(table *tab, program *node, char *func_type)
{
    program *stat;
    data_type type;
    char string[3 * STRING_SIZE];

    program *expr = node->children;
    type = check_expression(tab, expr);
    if (type == function_t)
    {
        sprintf(string, "Conflicting types (got %s, expected int)", function);
        print_error(string, node->children->line, node->children->column);
    }
    else if (type == double_t || type == undefined_t || type == void_t)
    {
        sprintf(string, "Conflicting types (got %s, expected int)", data_type_to_string(type));
        print_error(string, node->children->line, node->children->column);
    }

    if (node->children->next)
    {
        stat = node->children->next;

        check_statement(tab, stat, func_type);
    }

    if (node->children->next->next)
    {
        stat = node->children->next->next;

        check_statement(tab, stat, func_type);
    }
}

void check_while(table *tab, program *node, char *func_type)
{
    char string[3 * STRING_SIZE];
    data_type type;
    program *expr = node->children;

    type = check_expression(tab, expr);

    if (type == double_t || type == undefined_t || type == void_t)
    {
        sprintf(string, "Conflicting types (got %s, expected int)", data_type_to_string(type));
        print_error(string, node->children->line, node->children->column);
    }

    if (node->children->next)
    {
        program *stat = node->children->next;

        check_statement(tab, stat, func_type);
    }
}

void check_return(table *tab, program *node, char *func_type)
{
    char string[3 * STRING_SIZE], help[STRING_SIZE];
    program *expr = node->children;
    data_type type = check_expression(tab, expr);
    //FALTAM VERIFICAÇOES!
    //verificar se existe erro invalid use of void
    if ((strcmp(func_type, "Void") == 0) && strcmp(node->children->type, "Null") != 0 && type != void_t)
    {
        sprintf(string, "Conflicting types (got %s, expected void)", data_type_to_string(type));
        print_error(string, node->children->line, node->children->column);
        return;
    }

    if (node->children)
    {
        strcpy(help, func_type);
        *help = tolower(*help);
        if (compare_types(data_type_to_string(type), help) == 1)
        {
            sprintf(string, "Conflicting types (got %s, expected %s)", data_type_to_string(type), help);

            if (strcmp(node->children->type, "Null") != 0)
                print_error(string, node->children->line, node->children->column);
            else
                print_error(string, node->line, node->column);
        }
    }
}

void check_statlist(table *tab, program *node, char *func_type)
{
    //FALTAM VERIFICAÇOES!

    program *stat_list = node->children;

    while (stat_list)
    {
        check_statement(tab, stat_list, func_type);
        stat_list = stat_list->next;
    }
}

data_type check_expression(table *tab, program *node)
{
    char string[STRING_SIZE];
    if (strcmp(node->type, "Call") == 0)
    {
        //printf("call, %s\n", node->type);
        return check_call(tab, node);
    }
    else if (strcmp(node->type, "IntLit") == 0)
    {
        //printf("intlit, %s\n", node->type);
        sprintf(string, "IntLit(%s) - int", node->children->type);
        node->type = strdup(string);
        free(node->children);
        node->children = NULL;

        return int_t;
    }
    else if (strcmp(node->type, "ChrLit") == 0)
    {
        //printf("chrlit, %s\n", node->type);
        sprintf(string, "ChrLit(%s) - int", node->children->type);
        node->type = strdup(string);
        free(node->children);
        node->children = NULL;

        return int_t;
    }
    else if (strcmp(node->type, "RealLit") == 0)
    {
        //printf("reallit, %s\n", node->type);
        sprintf(string, "RealLit(%s) - double", node->children->type);
        node->type = strdup(string);
        free(node->children);
        node->children = NULL;

        return double_t;
    }
    else if (strcmp(node->type, "Id") == 0)
    {
        //printf("id, %s\n", node->type);
        return check_var(tab, node);
    }
    else if (strcmp(node->type, "Erro") == 0)
    {
        //printf("erro\n");
        //Ignorar erro
        return undefined_t;
    }
    else if (strcmp(node->type, "Not") == 0)
    {
        //printf("not, %s\n", node->type);
        return check_not(tab, node);
    }
    else if (strcmp(node->type, "Plus") == 0 || strcmp(node->type, "Minus") == 0)
    {
        //printf("plus minus, %s\n", node->type);
        return check_not(tab, node);
    }
    else if (strcmp(node->type, "BitWiseXor") == 0 ||
             strcmp(node->type, "BitWiseOr") == 0 ||
             strcmp(node->type, "BitWiseAnd") == 0 ||
             strcmp(node->type, "And") == 0 ||
             strcmp(node->type, "Or") == 0 ||
             strcmp(node->type, "Mod") == 0)
    {
        //printf("and or, %s\n", node->type);
        return check_binary_operation(tab, node);
    }
    else if (strcmp(node->type, "Gt") == 0 ||
             strcmp(node->type, "Lt") == 0 ||
             strcmp(node->type, "Ge") == 0 ||
             strcmp(node->type, "Le") == 0 ||
             strcmp(node->type, "Ne") == 0 ||
             strcmp(node->type, "Eq") == 0)
    {
        //printf("compare, %s\n", node->type);
        return check_comparison(tab, node);
    }
    else if (strcmp(node->type, "Div") == 0 ||
             strcmp(node->type, "Mul") == 0 ||
             strcmp(node->type, "Sub") == 0 ||
             strcmp(node->type, "Add") == 0 ||
             strcmp(node->type, "Store") == 0)
    {
        //printf("contas, %s\n", node->type);
        return check_operation(tab, node);
    }
    else if (strcmp(node->type, "Null") == 0)
    {
        //printf("null\n");
        return void_t;
    }
    else
    {
        //printf("comma\n");
        return check_commas(tab, node);
    }
}

data_type check_not(table *tab, program *node)
{
    //FALTAM VERIFICAÇOES!
    char help[3 * STRING_SIZE];
    program *expr = node->children;

    data_type type = check_expression(tab, expr);
    if (type == function_t)
    {
        sprintf(help, "Operator %s cannot be applied to type %s", string_to_operator(node->type), function);

        print_error(help, node->line, node->column);

        if (strcmp(node->type, "Not") == 0)
        {

            sprintf(help, "%s - %s", node->type, data_type_to_string(int_t));
            node->type = strdup(help);

            return int_t;
        }
        else
        {

            sprintf(help, "%s - %s", node->type, data_type_to_string(undefined_t));
            node->type = strdup(help);

            return undefined_t;
        }
    }

    if (type == void_t || type == undefined_t)
    {
        sprintf(help, "Operator %s cannot be applied to type %s", string_to_operator(node->type), data_type_to_string(type));

        print_error(help, node->line, node->column);

        if (strcmp(node->type, "Not") == 0)
        {
            sprintf(help, "%s - %s", node->type, data_type_to_string(int_t));
            node->type = strdup(help);

            return int_t;
        }
        else
        {

            sprintf(help, "%s - %s", node->type, data_type_to_string(undefined_t));
            node->type = strdup(help);

            return undefined_t;
        }
    }
    else if (strcmp(node->type, "Not") == 0)
    {
        if (type == double_t)
        {
            sprintf(help, "Operator %s cannot be applied to type %s", string_to_operator(node->type), data_type_to_string(type));
            print_error(help, node->line, node->column);
        }
        sprintf(help, "%s - %s", node->type, data_type_to_string(int_t));
        node->type = strdup(help);

        return int_t;
    }

    else
    {
        sprintf(help, "%s - %s", node->type, data_type_to_string(type));
        node->type = strdup(help);

        return type;
    }
}

data_type check_binary_operation(table *tab, program *node)
{
    program *child1 = node->children;
    program *child2 = node->children->next;
    char help[STRING_SIZE], help2[STRING_SIZE];
    data_type type_child1, type_child2;
    bool error;

    type_child1 = check_expression(tab, child1);
    if (type_child1 == function_t)
        strcpy(help, function);

    type_child2 = check_expression(tab, child2);
    if (type_child2 == function_t)
        strcpy(help2, function);

    error = check_function_type(help, help2, node, type_child1, type_child2);

    if (error)
    {
        sprintf(help, "%s - %s", node->type, data_type_to_string(int_t));
        node->type = strdup(help);
        //Operaçoes binarias dao sempre int
        return int_t;
    }

    if ((type_child1 == undefined_t || type_child2 == undefined_t) || type_child1 == double_t || type_child2 == double_t || type_child1 == void_t || type_child2 == void_t)
    {
        sprintf(help, "Operator %s cannot be applied to types %s, %s", string_to_operator(node->type), data_type_to_string(type_child1), data_type_to_string(type_child2));

        print_error(help, node->line, node->column);
    }

    sprintf(help, "%s - %s", node->type, data_type_to_string(int_t));
    node->type = strdup(help);
    //Operaçoes binarias dao sempre int
    return int_t;
}

data_type check_comparison(table *tab, program *node)
{
    program *child1 = node->children;
    program *child2 = node->children->next;
    char help[STRING_SIZE];
    data_type type_child1, type_child2;

    type_child1 = check_expression(tab, child1);
    type_child2 = check_expression(tab, child2);

    if ((type_child1 == undefined_t || type_child2 == undefined_t || type_child1 == void_t || type_child2 == void_t))
    {
        if ((type_child1 != undefined_t || type_child2 != undefined_t))
        {
            sprintf(help, "Operator %s cannot be applied to types %s, %s", string_to_operator(node->type), data_type_to_string(type_child1), data_type_to_string(type_child2));

            print_error(help, node->line, node->column);
        }
    }

    sprintf(help, "%s - %s", node->type, data_type_to_string(int_t));
    node->type = strdup(help);
    //Operaçoes binarias dao sempre int
    return int_t;
}

data_type check_operation(table *tab, program *node)
{
    char help[STRING_SIZE] = "", help2[STRING_SIZE] = "";
    program *child1 = node->children;
    program *child2 = node->children->next;
    bool error;

    data_type type_child1 = check_expression(tab, child1);
    if (type_child1 == function_t)
        strcpy(help, function);

    data_type type_child2 = check_expression(tab, child2);
    if (type_child2 == function_t)
        strcpy(help2, function);

    error = check_function_type(help, help2, node, type_child1, type_child2);

    if (error)
    {
        sprintf(help, "%s - %s", node->type, data_type_to_string(undefined_t));
        node->type = strdup(help);
        return undefined_t;
    }

    if (type_child1 == void_t || type_child2 == void_t || type_child1 == undefined_t || type_child2 == undefined_t)
    {

        sprintf(help, "Operator %s cannot be applied to types %s, %s", string_to_operator(node->type), data_type_to_string(type_child1), data_type_to_string(type_child2));

        if (strcmp(node->type, "Store") != 0 || type_child2 != void_t)
            print_error(help, node->line, node->column);

        if (strcmp(node->type, "Store") == 0)
        {
            if (*child1->type != 'I' || *(child1->type + 1) != 'd')
            {
                //O q esta a esquerda nao é Id
                sprintf(help, "Lvalue required");
                print_error(help, child1->line, child1->column);
            }
            sprintf(help, "%s - %s", node->type, data_type_to_string(type_child1));
            node->type = strdup(help);
            return type_child1;
        }

        sprintf(help, "%s - undef", node->type);
        node->type = strdup(help);

        return undefined_t;
    }

    else if (type_child1 == double_t || type_child2 == double_t)
    {
        if (strcmp(node->type, "Store") == 0)
        {
            if (*child1->type != 'I' || *(child1->type + 1) != 'd')
            {
                //O q esta a esquerda nao é Id
                sprintf(help, "Lvalue required");
                print_error(help, child1->line, child1->column);
            }

            if (type_child1 != double_t && type_child2 == double_t)
            {
                //int a = 5.6;
                sprintf(help, "Operator = cannot be applied to types %s, %s", data_type_to_string(type_child1), data_type_to_string(type_child2));
                print_error(help, node->line, node->column);
            }

            sprintf(help, "%s - %s", node->type, data_type_to_string(type_child1));
            node->type = strdup(help);

            return type_child1;
        }
        else
        {
            sprintf(help, "%s - %s", node->type, data_type_to_string(double_t));
            node->type = strdup(help);

            return double_t;
        }
    }
    else if (type_child1 == int_t || type_child2 == int_t)
    {
        if (strcmp(node->type, "Store") == 0)
        {
            if (*child1->type != 'I' || *(child1->type + 1) != 'd')
            {
                //O q esta a esquerda nao é Id
                sprintf(help, "Lvalue required");
                print_error(help, child1->line, child1->column);
            }
            sprintf(help, "%s - %s", node->type, data_type_to_string(type_child1));
            node->type = strdup(help);

            return type_child1;
        }
        else
        {
            sprintf(help, "%s - %s", node->type, data_type_to_string(int_t));
            node->type = strdup(help);

            return int_t;
        }
    }
    else if (type_child1 == short_t || type_child2 == short_t)
    {
        if (strcmp(node->type, "Store") == 0)
        {
            if (*child1->type != 'I' || *(child1->type + 1) != 'd')
            {
                //O q esta a esquerda nao é Id
                sprintf(help, "Lvalue required");
                print_error(help, child1->line, child1->column);
            }
            sprintf(help, "%s - %s", node->type, data_type_to_string(type_child1));
            node->type = strdup(help);

            return type_child1;
        }
        else
        {
            sprintf(help, "%s - %s", node->type, data_type_to_string(short_t));
            node->type = strdup(help);

            return short_t;
        }
    }
    else
    {
        if (strcmp(node->type, "Store") == 0)
        {
            if (*child1->type != 'I' || *(child1->type + 1) != 'd')
            {
                //O q esta a esquerda nao é Id
                sprintf(help, "Lvalue required");
                print_error(help, child1->line, child1->column);
            }
            sprintf(help, "%s - %s", node->type, data_type_to_string(type_child1));
            node->type = strdup(help);

            return type_child1;
        }
        //char
        sprintf(help, "%s - %s", node->type, data_type_to_string(type_child1));
        node->type = strdup(help);

        return type_child1;
    }
}

data_type check_commas(table *tab, program *node)
{
    data_type type_child1, type_child2;
    program *child1 = node->children;
    program *child2 = node->children->next;
    char help[STRING_SIZE], help2[STRING_SIZE], string[4 * STRING_SIZE];
    bool error;

    type_child1 = check_expression(tab, child1);
    if (type_child1 == function_t)
        strcpy(help, function);

    type_child2 = check_expression(tab, child2);
    if (type_child2 == function_t)
        strcpy(help2, function);

    error = check_function_type(help, help2, node, type_child1, type_child2);

    if (error)
    {
        sprintf(help, "Comma - %s", data_type_to_string(undefined_t));
        node->type = strdup(help);
        return undefined_t;
    }

    if (type_child1 == undefined_t || type_child2 == undefined_t)
    {
        sprintf(string, "Operator %s cannot be applied to types %s, %s", string_to_operator(node->type), data_type_to_string(type_child1), data_type_to_string(type_child2));
        print_error(string, node->line, node->column);

        sprintf(help, "Comma - %s", data_type_to_string(undefined_t));
        node->type = strdup(help);

        return undefined_t;
    }

    sprintf(help, "Comma - %s", data_type_to_string(type_child2));
    node->type = strdup(help);

    return type_child2;
}

char *data_type_to_string(data_type type)
{
    if (type == int_t)
    {
        return strdup("int");
    }
    else if (type == char_t)
    {
        return strdup("char");
    }
    else if (type == short_t)
    {
        return strdup("short");
    }
    else if (type == double_t)
    {
        return strdup("double");
    }
    else if (type == void_t)
    {
        return strdup("void");
    }
    else if (type == undefined_t)
    {
        return strdup("undef");
    }
    else
    {
        printf("\n\nERRO, N DEVIA ACONTECER\n\n");
        return NULL;
    }
}

data_type check_call(table *tab, program *node)
{
    char help[STRING_SIZE], help2[STRING_SIZE * 2], string[STRING_SIZE];
    func_declaration *function;
    func_parameter *param;
    var_declaration *var;
    program *aux_node;
    data_type type;
    int i_param = 0, e_param = 0;
    //node -> type é "Call"
    //node -> children é o ID
    //node -> children -> next sao os parametros

    //procurar no global scope, so ai e que ha funçoes
    function = search_function(node->children, symtab);

    if (!function)
    {
        if ((var = search_variable(node->children->children->type, tab)) || (var = search_variable(node->children->children->type, symtab)))
        {
            sprintf(help, "Call - %s", var->type);
            node->type = strdup(help);
            sprintf(help, "Id(%s) - %s", node->children->children->type, var->type);
        }
        else
        {
            sprintf(help, "Unknown symbol %s", node->children->children->type);
            print_error(help, node->children->line, node->children->column);
            node->type = strdup("Call - undef");
            sprintf(help, "Id(%s) - undef", node->children->children->type);
        }

        node->children->type = strdup(help);

        aux_node = node->children->next;
        while (aux_node)
        {
            check_expression(tab, aux_node);
            aux_node = aux_node->next;
            i_param++;
        }
        if (i_param != 0)
        {
            sprintf(help, "Wrong number of arguments to function %s (got %d, required 0)", node->children->children->type, i_param);
            print_error(help, node->children->line, node->children->column);
        }

        free(node->children->children);
        node->children->children = NULL;
        return undefined_t;
    }

    //reescrever "Call"
    sprintf(help, "Call - %s", function->type);
    node->type = strdup(help);

    //reescrever ID - precisamos do ID, o return value e os tipos dos parametros
    param = function->parameters;
    strcpy(help, param->type);

    param = param->next;
    while (param != NULL)
    {
        strcat(help, ",");
        strcat(help, param->type);
        param = param->next;
    }

    sprintf(help2, "Id(%s) - %s(%s)", node->children->children->type, function->type, help);
    node->children->type = strdup(help2);

    //verificar parametros
    aux_node = node->children->next; //parametros do input
    param = function->parameters;    //parâmetros da funçao(esperados)

    if (strcmp(param->type, "void") != 0)
        e_param++;

    i_param = 0;

    //TODO verificar tipos do parametro
    if (aux_node)
    {
        type = check_expression(tab, aux_node);

        if (string_to_data_type(param->type) != void_t && compare_types(data_type_to_string(type), param->type) != 0)
        {
            sprintf(string, "Conflicting types (got %s, expected %s)", data_type_to_string(type), param->type);
            if (*aux_node->type == 'C' && *(aux_node->type + 1) == 'a')
            {
                print_error(string, aux_node->children->line, aux_node->children->column);
            }
            else
                print_error(string, aux_node->line, aux_node->column);
        }

        aux_node = aux_node->next;
        i_param++;
    }
    param = param->next;

    //func_params     call_params
    while (param != NULL && aux_node != NULL)
    {
        //TODO verificar tipos do parametro
        type = check_expression(tab, aux_node);
        if (compare_types(data_type_to_string(type), param->type) != 0)
        {
            sprintf(string, "Conflicting types (got %s, expected %s)", data_type_to_string(type), param->type);

            if (*aux_node->type == 'C' && *(aux_node->type + 1) == 'a')
            {
                print_error(string, aux_node->children->line, aux_node->children->column);
            }
            else
                print_error(string, aux_node->line, aux_node->column);
        }
        param = param->next;
        e_param++;
        aux_node = aux_node->next;
        i_param++;
    }

    if (param || aux_node)
    {
        //ou temos parametros a mais ou parametros a menos
        if (param)
        {
            while (param)
            {
                param = param->next;
                e_param++;
            }
        }
        else if (aux_node)
        {
            //parametros a mais!
            while (aux_node)
            {
                type = check_expression(tab, aux_node);

                if (strcmp(aux_node->type, "Id") == 0)
                {
                    //parametro é um ID
                    sprintf(help, "Id(%s) - %s", aux_node->children->type, data_type_to_string(type));
                    aux_node->type = strdup(help);
                    free(aux_node->children);
                    aux_node->children = NULL;
                }
                aux_node = aux_node->next;
                i_param++;
            }
        }
    }

    //TODO verificar se o numero de parametros esta certo
    if (e_param != i_param)
    {
        sprintf(help2, "Wrong number of arguments to function %s (got %d, required %d)", node->children->children->type, i_param, e_param);
        print_error(help2, node->children->line, node->children->column);
    }

    free(node->children->children);
    node->children->children = NULL;

    return string_to_data_type(function->type);
}

data_type check_var(table *tab, program *node)
{
    char help[3 * STRING_SIZE];
    var_declaration *variable;
    func_declaration *func;
    //node é o ID

    //procurar no local scope
    variable = search_variable(node->children->type, tab);

    if (!variable)
    {
        //procurar no global scope
        variable = search_variable(node->children->type, symtab);
    }

    if (!variable)
    {
        //procurar nas funçoes
        func = search_function(node, symtab);
        if (func)
        {
            function_declarator(help, function, func->parameters, func->type);

            sprintf(help, "Id(%s) - %s", node->children->type, function);
            free(node->children);
            node->children = NULL;
            node->type = strdup(help);

            return function_t;
        }

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

    return string_to_data_type(variable->type);
}

data_type string_to_data_type(char *type)
{
    if (strcmp(type, "int") == 0)
        return int_t;
    else if (strcmp(type, "short") == 0)
        return short_t;
    else if (strcmp(type, "double") == 0)
        return double_t;
    else if (strcmp(type, "char") == 0)
        return char_t;
    else if (strcmp(type, "void") == 0)
        return void_t;
    else
    {
        printf("\n\nERRO, N DEVIA ACONTECER\n\n");
        return undefined_t;
    }
}

char *string_to_operator(char *str)
{
    if (strcmp(str, "Add") == 0 || strcmp(str, "Plus") == 0)
    {
        return strdup("+");
    }
    else if (strcmp(str, "Store") == 0)
    {
        return strdup("=");
    }
    else if (strcmp(str, "Sub") == 0 || strcmp(str, "Minus") == 0)
    {
        return strdup("-");
    }
    else if (strcmp(str, "Mul") == 0)
    {
        return strdup("*");
    }
    else if (strcmp(str, "Div") == 0)
    {
        return strdup("/");
    }
    else if (strcmp(str, "Mod") == 0)
    {
        return strdup("%");
    }
    else if (strcmp(str, "Or") == 0)
    {
        return strdup("||");
    }
    else if (strcmp(str, "And") == 0)
    {
        return strdup("&&");
    }
    else if (strcmp(str, "BitWiseAnd") == 0)
    {
        return strdup("&");
    }
    else if (strcmp(str, "BitWiseOr") == 0)
    {
        return strdup("|");
    }
    else if (strcmp(str, "BitWiseXor") == 0)
    {
        return strdup("^");
    }
    else if (strcmp(str, "Eq") == 0)
    {
        return strdup("==");
    }
    else if (strcmp(str, "Ne") == 0)
    {
        return strdup("!=");
    }
    else if (strcmp(str, "Le") == 0)
    {
        return strdup("<=");
    }
    else if (strcmp(str, "Ge") == 0)
    {
        return strdup(">=");
    }
    else if (strcmp(str, "Lt") == 0)
    {
        return strdup("<");
    }
    else if (strcmp(str, "Gt") == 0)
    {
        return strdup(">");
    }
    else if (strcmp(str, "Not") == 0)
    {
        return strdup("!");
    }
    else if (strcmp(str, "RealComma") == 0)
    {
        return strdup(",");
    }
    else if (strcmp(str, "Comma") == 0)
    {
        return strdup(",");
    }
    return NULL;
}

int compare_types(char *first, char *second)
{
    if (strcmp(first, "int") == 0 || strcmp(first, "char") == 0 || strcmp(first, "short") == 0)
    {
        if (strcmp(second, "void") == 0 || strcmp(second, "undef") == 0)
        {
            //invalido
            return 1;
        }
        else
        {
            //valido
            return 0;
        }
    }
    else if (strcmp(first, "double") == 0 || strcmp(first, "void") == 0)
    {
        if (strcmp(second, "int") == 0 || strcmp(second, "char") == 0 || strcmp(second, "short") == 0 || strcmp(second, "undef") == 0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else if (strcmp(first, "undef") == 0)
    {
        if (strcmp(second, "undef") != 0)
        {
            //invalido
            return 1;
        }
        else
        {
            //valido
            return 0;
        }
    }
    else
    {
        return 0;
    }
}

bool check_function_type(char *help, char *help2, program *node, data_type type1, data_type type2)
{
    char string[4 * STRING_SIZE];
    if (type1 == function_t && type2 == function_t)
    {
        sprintf(string, "Operator %s cannot be applied to types %s, %s", string_to_operator(node->type), help, help2);
        print_error(string, node->line, node->column);
        return true;
    }
    else if (type1 == function_t && type2 != function_t)
    {
        sprintf(string, "Operator %s cannot be applied to types %s, %s", string_to_operator(node->type), help, data_type_to_string(type2));
        print_error(string, node->line, node->column);
        return true;
    }
    else if (type1 != function_t && type2 == function_t)
    {
        sprintf(string, "Operator %s cannot be applied to types %s, %s", string_to_operator(node->type), data_type_to_string(type1), help2);
        print_error(string, node->line, node->column);
        return true;
    }
    else
    {
        return false;
    }
}