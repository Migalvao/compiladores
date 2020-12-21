#include "gen_code.h"

int num_registo, tab_indent = 0, if_num, while_num;
table *function_table = NULL;
extern table *symtab;
bool main_defined = false;
global_var_expression *global_var_list = NULL;
char *type = NULL;

void start_program(program *prog)
{
    program *my_program = prog->children;
    char string[50];

    printf("declare i32 @putchar(i32)\n");
    printf("declare i32 @getchar()\n");

    while (my_program)
    {
        if (strcmp(my_program->type, "FuncDefinition") == 0)
        {
            function_def(my_program);
        }
        else if (strcmp(my_program->type, "FuncDeclaration") == 0)
        {
            sprintf(string, "Function %s", my_program->children->next->children->type);
            if (!search_table(string))
                function_dec(my_program);
        }
        //DECLARATION
        else
        {
            declaration(my_program, true);
            //declaraçao global
        }

        my_program = my_program->next;
    }
}

void function_def(program *node)
{
    //node - FuncDefinition
    //node->children - tipo de funcao
    //node->children->next - nome da funcao
    //node->children->next->next - se tem ou nao paramlist
    //node->children->next->next->next - func body

    //DEFINIÇAO DE FUNCAO
    program *param;
    char table_name[50];
    num_registo = if_num = while_num = 1;

    printf("define %s @%s(", var_type(node->children->type), node->children->next->children->type);

    sprintf(table_name, "Function %s", node->children->next->children->type);
    type = strdup(var_type(node->children->type));
    function_table = search_table(table_name);

    if (strcmp(node->children->next->next->type, "ParamList") == 0)
    {
        param = node->children->next->next->children;
        //Este if ve se existe parametros ou nao na funcao (node->children->next->next->children->children->type = tipo de parametro)
        if (strcmp(node->children->next->next->children->children->type, "Void") == 0)
        {
            printf(") {\n");
        }
        else
        {
            printf("%s %%arg-%s", var_type(param->children->type), param->children->next->children->type);

            param = param->next;

            if (param)
            {
                while (param)
                {
                    printf(", %s %%arg-%s", var_type(param->children->type), param->children->next->children->type);
                    param = param->next;
                }
            }

            printf(") {\n");
        }
    }
    //printf("%%1 = alloca i32, align 4\n");
    //printf("store i32 0, i32* %%1, align 4\n");

    if (strcmp(node->children->next->children->type, "main") == 0)
    {
        //inicializar variaveis globais
        initialize_global_vars();
    }

    param = node->children->next->next->children;
    //Este if ve se existe parametros ou nao na funcao (node->children->next->next->children->children->type = tipo de parametro)
    if (strcmp(node->children->next->next->children->children->type, "Void") != 0)
    {
        printf("%%%s = alloca %s, align %d\n", param->children->next->children->type, var_type(param->children->type), size(param->children->type));
        printf("store %s %%arg-%s, %s* %%%s\n", var_type(param->children->type), param->children->next->children->type, var_type(param->children->type), param->children->next->children->type);

        param = param->next;

        if (param)
        {
            while (param)
            {
                printf("%%%s = alloca %s, align %d\n", param->children->next->children->type, var_type(param->children->type), size(param->children->type));
                printf("store %s %%arg-%s, %s* %%%s\n", var_type(param->children->type), param->children->next->children->type, var_type(param->children->type), param->children->next->children->type);

                param = param->next;
            }
        }
    }

    tab_indent++;
    function_body(node->children->next->next->next);
    tab_indent--;

    printf("}\n");
}

void function_dec(program *node)
{
    program *param;
    //DECLARAÇAO DE FUNCAO
    printf("declare %s @%s(", var_type(node->children->type), node->children->next->children->type);

    if (strcmp(node->children->next->next->type, "ParamList") == 0)
    {
        param = node->children->next->next->children;
        //Este if ve se existe parametros ou nao na funcao (node->children->next->next->children->children->type = tipo de parametro)
        if (strcmp(node->children->next->next->children->children->type, "Void") == 0)
        {
            //printf("via");
            printf(")\n");
        }
        else
        {
            //printf("%s", var_type(param->children->type));

            printf("%s %%%s", var_type(param->children->type), param->children->next->children->type);

            param = param->next;

            if (param)
            {
                while (param)
                {
                    //printf(", %s", var_type(param->children->type));
                    printf(", %s %%%s", var_type(param->children->type), param->children->next->children->type);
                    param = param->next;
                }
            }

            printf(")\n");
        }
    }
}

bool function_body(program *func_body)
{
    //printf("BODY\n");
    program *body;
    bool single_statement = false, has_return = false;
    char string[100], string2[200], params[400];
    func_declaration *func_call;

    if (strcmp(func_body->type, "FuncBody") == 0 || strcmp(func_body->type, "StatList") == 0)
    {
        body = func_body->children;
    }
    else
    {
        //Só um statement
        body = func_body;
        single_statement = true;
    }

    if (!body && strcmp(func_body->type, "FuncBody") == 0)
    {
        //function body vazio -> por um return por default
        if (!type)
        {
            printf("NAO DEVIA ACONTECER\n");
        }
        else if (strcmp(type, "void") == 0)
        {
            printf("ret %s\n", type);
        }
        else if (strcmp(type, "double") == 0)
        {
            printf("ret %s 0.0\n", type);
        }
        else
        {
            printf("ret %s 0\n", type);
        }
    }

    while (body)
    {
        print_tab(tab_indent);

        //Store
        if (strcmp(body->type, "Store") == 0)
        {
            if (strcmp(body->annotation, "double") == 0)
                strcpy(string, expression(body->children->next, true, false));
            else
                strcpy(string, expression(body->children->next, false, true));

            print_tab(tab_indent);

            if (function_table && search_variable(body->children->children->type, function_table))
            {
                //variavel local
                printf("store %s %s, %s* %%%s\n", var_type(body->annotation), string, var_type(body->children->annotation), body->children->children->type);
            }
            else
            {
                //variavel global
                printf("store %s %s, %s* @%s\n", var_type(body->annotation), string, var_type(body->children->annotation), body->children->children->type);
            }
        }
        else if (strcmp(body->type, "Declaration") == 0)
        {
            declaration(body, false);
        }
        else if (strcmp(body->type, "Return") == 0)
        {
            if (strcmp(type, "double") == 0)
            {
                strcpy(string, expression(body->children, true, false));
            }
            else if (strcmp(type, "void") == 0)
            {
                strcpy(string, "");
            }
            else
            {
                strcpy(string, expression(body->children, false, true));
            }
            print_tab(tab_indent);
            printf("ret %s %s\n", type, string);
            has_return = true;
        }
        else if (strcmp(body->type, "Call") == 0)
        {
            func_call = search_function(body->children, symtab);

            if (body->children->next)
            {
                program *param;
                func_parameter *param2;
                param = body->children->next;
                param2 = func_call->parameters;

                if (strcmp(var_type(param2->type), "double") == 0)
                {
                    strcpy(string, expression(param, true, false));
                }
                else
                {
                    strcpy(string, expression(param, false, true));
                }

                sprintf(params, "%s %s", var_type(param2->type), string);

                if (param->next)
                {
                    param = param->next;
                    param2 = param2->next;
                    while (param)
                    {
                        if (strcmp(var_type(param2->type), "double") == 0)
                        {
                            strcpy(string, expression(param, true, false));
                        }
                        else
                        {
                            strcpy(string, expression(param, false, true));
                        }
                        sprintf(string2, ", %s %s", var_type(param2->type), string);
                        strcat(params, string2);

                        param = param->next;
                        param2 = param2->next;
                    }
                }
                if (strcmp(body->annotation, "void") != 0)
                    printf("%%%d = call %s @%s(%s)\n", num_registo++, var_type(body->annotation), body->children->children->type, params);
                else
                    printf("call %s @%s(%s)\n", var_type(body->annotation), body->children->children->type, params);
            }
            else
            {
                //nao tem parametros
                if (strcmp(body->annotation, "void") != 0)
                    printf("%%%d = call %s @%s()\n", num_registo++, var_type(body->annotation), body->children->children->type);
                else
                    printf("call %s @%s()\n", var_type(body->annotation), body->children->children->type);
            }
        }
        else if (strcmp(body->type, "If") == 0)
        {
            check_gen_if(body);
        }
        else if (strcmp(body->type, "While") == 0)
        {
            check_gen_while(body);
        }
        else
        {
            //expression
            expression(body, false, false);
        }

        if (single_statement)
            return has_return;

        if (!body->next && strcmp(body->type, "Return") != 0 && strcmp(func_body->type, "StatList") != 0)
        {
            //funçao termina sem um return
            if (!type)
            {
                printf("NAO DEVIA ACONTECER\n");
            }
            else if (strcmp(type, "void") == 0)
            {
                printf("ret %s\n", type);
            }
            else if (strcmp(type, "double") == 0)
            {
                printf("ret %s 0.0\n", type);
            }
            else
            {
                printf("ret %s 0\n", type);
            }
        }

        body = body->next;
    }
    return has_return;
}

char *expression(program *expr, bool to_double, bool to_i32)
{
    char value[VALUE_SIZE], string[100], params[300], string2[10];
    func_declaration *func_call;

    print_tab(tab_indent);

    if (strcmp(expr->type, "ChrLit") == 0)
    {
        if (to_double)
        {
            sprintf(value, "%d.0", charlit_to_int(expr->children->type));
            return strdup(value);
        }
        else
        {
            sprintf(value, "%d", charlit_to_int(expr->children->type));
            return strdup(value);
        }
    }
    else if (strcmp(expr->type, "IntLit") == 0)
    {
        int number;
        if (*expr->children->type == '0' && strlen(expr->children->type) > 1)
        {
            sscanf(expr->children->type, "%o", &number);

            if (to_double)
            {
                sprintf(value, "%d.0", number);
                return strdup(value);
            }
            else
            {
                sprintf(value, "%d", number);
                return strdup(value);
            }
        }
        if (to_double)
        {
            sprintf(value, "%s.0", expr->children->type);
            return strdup(value);
        }
        else
        {
            sprintf(value, "%s", expr->children->type);
            return strdup(value);
        }
    }
    else if (strcmp(expr->type, "RealLit") == 0)
    {
        double num;
        sscanf(expr->children->type, "%lf", &num);
        sprintf(value, "%lf", num);
        return strdup(value);
    }
    else if (strcmp(expr->type, "Id") == 0)
    {
        if (function_table && search_variable(expr->children->type, function_table))
        {
            //variavel local
            printf("%%%d = load %s, %s* %%%s\n", num_registo, var_type(expr->annotation), var_type(expr->annotation), expr->children->type);
            sprintf(value, "%%%d", num_registo++);
            if (to_double && strcmp(var_type(expr->annotation), "double") != 0)
            {
                i32_to_double(value);
            }
            else if (!to_double && !to_i32)
            {
                i32_to_i1(value);
            }
        }
        else
        {
            //variavel global
            printf("%%%d = load %s, %s* @%s\n", num_registo, var_type(expr->annotation), var_type(expr->annotation), expr->children->type);
            sprintf(value, "%%%d", num_registo++);
            if (to_double && strcmp(var_type(expr->annotation), "double") != 0)
            {
                i32_to_double(value);
            }
            else if (!to_double && !to_i32)
            {
                i32_to_i1(value);
            }
        }

        return strdup(value);
    }

    else if (strcmp(expr->type, "Store") == 0)
    {
        //TODO pode faltar verificar se e double
        if (strcmp(expr->annotation, "double") == 0)
            sprintf(value, "%s", expression(expr->children->next, true, false));
        else
        {
            sprintf(value, "%s", expression(expr->children->next, false, true));
        }

        if (function_table && search_variable(expr->children->children->type, function_table))
            printf("store %s %s, %s* %%%s\n", var_type(expr->annotation), value, var_type(expr->children->annotation), expr->children->children->type);
        else
            printf("store %s %s, %s* @%s\n", var_type(expr->annotation), value, var_type(expr->children->annotation), expr->children->children->type);

        if (to_double)
        {
            sprintf(value, "%s", expression(expr->children->next, true, false));
        }
        /*
        else if (!to_i32)
        {
            sprintf(value, "%s", expression(expr->children->next, false, false));
        }*/

        return strdup(value);
    }

    else if (strcmp(expr->type, "Call") == 0)
    {
        func_call = search_function(expr->children, symtab);
        if (expr->children->next)
        {
            program *param;
            func_parameter *param2;
            param = expr->children->next;
            param2 = func_call->parameters;

            if (strcmp(var_type(param2->type), "double") == 0)
            {
                strcpy(value, expression(param, true, false));
            }
            else
            {
                strcpy(value, expression(param, false, true));
            }
            sprintf(params, "%s %s", var_type(param2->type), value);

            if (param->next)
            {
                param = param->next;
                param2 = param2->next;
                while (param)
                {
                    if (strcmp(var_type(param2->type), "double") == 0)
                    {
                        strcpy(value, expression(param, true, false));
                    }
                    else
                    {
                        strcpy(value, expression(param, false, true));
                    }
                    sprintf(string, ", %s %s", var_type(param2->type), value);
                    strcat(params, string);
                    param = param->next;
                    param2 = param2->next;
                }
            }
            if (strcmp(expr->annotation, "void") != 0)
            {
                printf("%%%d = call %s @%s(%s)\n", num_registo, var_type(expr->annotation), expr->children->children->type, params);
                sprintf(value, "%%%d", num_registo++);

                if (strcmp(var_type(expr->annotation), "i32") == 0 && to_double)
                {
                    i32_to_double(value);
                }
                else if (!to_i32 && !to_double)
                {
                    i32_to_i1(value);
                }
                return strdup(value);
            }
            else
            {
                printf("RETURN VOID?\n");
                return NULL;
            }
        }
        else
        {
            //nao tem parametros
            if (strcmp(expr->annotation, "void") != 0)
            {
                printf("%%%d = call %s @%s()\n", num_registo, var_type(expr->annotation), expr->children->children->type);
                sprintf(value, "%%%d", num_registo++);

                if (strcmp(var_type(expr->annotation), "i32") == 0 && to_double)
                {
                    i32_to_double(value);
                }
                else if (!to_i32)
                {
                    i32_to_i1(value);
                }

                return strdup(value);
            }
            else
            {
                printf("RETURN VOID?\n");
                return NULL;
            }
        }
    }
    else if (strcmp(expr->type, "Or") == 0)
    {
        strcpy(string, expression(expr->children, false, true));
        strcpy(string2, expression(expr->children->next, false, true));
        printf("%%%d = or %s %s, %s\n", num_registo, var_type(expr->annotation), string, string2);
        sprintf(value, "%%%d", num_registo++);
        if (to_double)
        {
            i32_to_double(value);
        }
        else if (!to_i32)
        {
            i32_to_i1(value);
        }
        return strdup(value);
    }
    else if (strcmp(expr->type, "And") == 0)
    {
        strcpy(string, expression(expr->children, false, true));
        strcpy(string2, expression(expr->children->next, false, true));
        printf("%%%d = and %s %s, %s\n", num_registo, var_type(expr->annotation), string, string2);
        sprintf(value, "%%%d", num_registo++);
        if (to_double)
        {
            i32_to_double(value);
        }
        else if (!to_i32)
        {
            i32_to_i1(value);
        }
        return strdup(value);
    }
    else if (strcmp(expr->type, "BitWiseAnd") == 0)
    {
        strcpy(string, expression(expr->children, false, true));
        strcpy(string2, expression(expr->children->next, false, true));
        printf("%%%d = and %s %s, %s\n", num_registo, var_type(expr->annotation), string, string2);
        sprintf(value, "%%%d", num_registo++);
        if (to_double)
        {
            i32_to_double(value);
        }
        else if (!to_i32)
        {
            i32_to_i1(value);
        }
        return strdup(value);
    }
    else if (strcmp(expr->type, "BitWiseOr") == 0)
    {
        strcpy(string, expression(expr->children, false, true));
        strcpy(string2, expression(expr->children->next, false, true));
        printf("%%%d = or %s %s, %s\n", num_registo, var_type(expr->annotation), string, string2);
        sprintf(value, "%%%d", num_registo++);
        if (to_double)
        {
            i32_to_double(value);
        }
        else if (!to_i32)
        {
            i32_to_i1(value);
        }
        return strdup(value);
    }
    else if (strcmp(expr->type, "BitWiseXor") == 0)
    {
        strcpy(string, expression(expr->children, false, true));
        strcpy(string2, expression(expr->children->next, false, true));
        printf("%%%d = xor %s %s, %s\n", num_registo, var_type(expr->annotation), string, string2);
        sprintf(value, "%%%d", num_registo++);
        if (to_double)
        {
            i32_to_double(value);
        }
        else if (!to_i32)
        {
            i32_to_i1(value);
        }
        return strdup(value);
    }

    else if (strcmp(expr->type, "Eq") == 0)
    {
        if (strcmp(expr->children->annotation, "double") == 0 || strcmp(expr->children->next->annotation, "double") == 0)
        {
            strcpy(string, expression(expr->children, true, false));
            strcpy(string2, expression(expr->children->next, true, false));
            printf("%%%d = fcmp oeq double %s, %s\n", num_registo, string, string2);
        }
        else
        {
            strcpy(string, expression(expr->children, false, true));
            strcpy(string2, expression(expr->children->next, false, true));
            printf("%%%d = icmp eq i32 %s, %s\n", num_registo, string, string2);
        }
        sprintf(value, "%%%d", num_registo++);
        if (to_i32)
        {
            i1_to_i32(value);
        }
        else if (to_double)
        {
            i1_to_double(value);
        }
        return strdup(value);
    }
    else if (strcmp(expr->type, "Ne") == 0)
    {
        if (strcmp(expr->children->annotation, "double") == 0 || strcmp(expr->children->next->annotation, "double") == 0)
        {
            strcpy(string, expression(expr->children, true, false));
            strcpy(string2, expression(expr->children->next, true, false));
            printf("%%%d = fcmp one double %s, %s\n", num_registo, string, string2);
        }
        else
        {
            strcpy(string, expression(expr->children, false, true));
            strcpy(string2, expression(expr->children->next, false, true));
            printf("%%%d = icmp ne i32 %s, %s\n", num_registo, string, string2);
        }

        sprintf(value, "%%%d", num_registo++);
        if (to_i32)
        {
            i1_to_i32(value);
        }
        else if (to_double)
        {
            i1_to_double(value);
        }
        return strdup(value);
    }
    else if (strcmp(expr->type, "Le") == 0)
    {
        if (strcmp(expr->children->annotation, "double") == 0 || strcmp(expr->children->next->annotation, "double") == 0)
        {
            strcpy(string, expression(expr->children, true, false));
            strcpy(string2, expression(expr->children->next, true, false));
            printf("%%%d = fcmp ole double %s, %s\n", num_registo, string, string2);
        }
        else
        {
            strcpy(string, expression(expr->children, false, true));
            strcpy(string2, expression(expr->children->next, false, true));
            printf("%%%d = icmp sle i32 %s, %s\n", num_registo, string, string2);
        }

        sprintf(value, "%%%d", num_registo++);
        if (to_i32)
        {
            i1_to_i32(value);
        }
        else if (to_double)
        {
            i1_to_double(value);
        }
        return strdup(value);
    }
    else if (strcmp(expr->type, "Ge") == 0)
    {
        if (strcmp(expr->children->annotation, "double") == 0 || strcmp(expr->children->next->annotation, "double") == 0)
        {
            strcpy(string, expression(expr->children, true, false));
            strcpy(string2, expression(expr->children->next, true, false));
            printf("%%%d = fcmp oge double %s, %s\n", num_registo, string, string2);
        }
        else
        {
            strcpy(string, expression(expr->children, false, true));
            strcpy(string2, expression(expr->children->next, false, true));
            printf("%%%d = icmp sge i32 %s, %s\n", num_registo, string, string2);
        }

        sprintf(value, "%%%d", num_registo++);
        if (to_i32)
        {
            i1_to_i32(value);
        }
        else if (to_double)
        {
            i1_to_double(value);
        }
        return strdup(value);
    }
    else if (strcmp(expr->type, "Lt") == 0)
    {
        if (strcmp(expr->children->annotation, "double") == 0 || strcmp(expr->children->next->annotation, "double") == 0)
        {
            strcpy(string, expression(expr->children, true, false));
            strcpy(string2, expression(expr->children->next, true, false));
            printf("%%%d = fcmp olt double %s, %s\n", num_registo, string, string2);
        }
        else
        {
            strcpy(string, expression(expr->children, false, true));
            strcpy(string2, expression(expr->children->next, false, true));
            printf("%%%d = icmp slt i32 %s, %s\n", num_registo, string, string2);
        }

        sprintf(value, "%%%d", num_registo++);
        if (to_i32)
        {
            i1_to_i32(value);
        }
        else if (to_double)
        {
            i1_to_double(value);
        }
        return strdup(value);
    }
    else if (strcmp(expr->type, "Gt") == 0)
    {
        if (strcmp(expr->children->annotation, "double") == 0 || strcmp(expr->children->next->annotation, "double") == 0)
        {
            strcpy(string, expression(expr->children, true, false));
            strcpy(string2, expression(expr->children->next, true, false));
            printf("%%%d = fcmp ogt double %s, %s\n", num_registo, string, string2);
        }
        else
        {
            strcpy(string, expression(expr->children, false, true));
            strcpy(string2, expression(expr->children->next, false, true));
            printf("%%%d = icmp sgt i32 %s, %s\n", num_registo, string, string2);
        }

        sprintf(value, "%%%d", num_registo++);
        if (to_i32)
        {
            i1_to_i32(value);
        }
        else if (to_double)
        {
            i1_to_double(value);
        }
        return strdup(value);
    }
    else if (strcmp(expr->type, "Not") == 0)
    {
        strcpy(string, expression(expr->children, false, true));
        printf("%%%d = xor i32 %s, 1\n", num_registo, string);
        sprintf(value, "%%%d", num_registo++);
        if (to_double)
        {
            i32_to_double(value);
        }
        else if (!to_i32)
        {
            i32_to_i1(value);
        }
        return strdup(value);
    }
    else if (strcmp(expr->type, "Plus") == 0)
    {
        if (strcmp(expr->annotation, "double") == 0)
        {
            strcpy(string, expression(expr->children, true, false));
            printf("%%%d = fadd %s %s, 0.0\n", num_registo, var_type(expr->annotation), string);
            sprintf(value, "%%%d", num_registo++);
            return strdup(value);
        }
        else
        {
            strcpy(string, expression(expr->children, false, true));
            printf("%%%d = add %s %s, 0\n", num_registo, var_type(expr->annotation), string);
            sprintf(value, "%%%d", num_registo++);
            if (to_double)
            {
                i32_to_double(value);
            }
            else if (!to_i32)
            {
                i32_to_i1(value);
            }
            return strdup(value);
        }
    }
    else if (strcmp(expr->type, "Minus") == 0)
    {
        if (strcmp(expr->annotation, "double") == 0)
        {
            strcpy(string, expression(expr->children, true, false));
            printf("%%%d = fsub %s 0.0, %s\n", num_registo, var_type(expr->annotation), string);
            sprintf(value, "%%%d", num_registo++);
            return strdup(value);
        }
        else
        {
            strcpy(string, expression(expr->children, false, true));
            printf("%%%d = sub %s 0, %s\n", num_registo, var_type(expr->annotation), string);
            sprintf(value, "%%%d", num_registo++);
            if (to_double)
            {
                i32_to_double(value);
            }
            else if (!to_i32)
            {
                i32_to_i1(value);
            }
            return strdup(value);
        }
    }
    else if (strcmp(expr->type, "Add") == 0)
    {
        if (strcmp(expr->annotation, "double") == 0)
        {
            strcpy(string, expression(expr->children, true, false));
            strcpy(string2, expression(expr->children->next, true, false));
            printf("%%%d = fadd %s %s, %s\n", num_registo, var_type(expr->annotation), string, string2);
            sprintf(value, "%%%d", num_registo++);
            return strdup(value);
        }
        else
        {
            strcpy(string, expression(expr->children, false, true));
            strcpy(string2, expression(expr->children->next, false, true));
            printf("%%%d = add %s %s, %s\n", num_registo, var_type(expr->annotation), string, string2);
            sprintf(value, "%%%d", num_registo++);
            if (to_double)
            {
                i32_to_double(value);
            }
            else if (!to_i32)
            {
                i32_to_i1(value);
            }
            return strdup(value);
        }
    }
    else if (strcmp(expr->type, "Sub") == 0)
    {
        if (strcmp(expr->annotation, "double") == 0)
        {
            strcpy(string, expression(expr->children, true, false));
            strcpy(string2, expression(expr->children->next, true, false));
            printf("%%%d = fsub %s %s, %s\n", num_registo, var_type(expr->annotation), string, string2);
            sprintf(value, "%%%d", num_registo++);
            return strdup(value);
        }
        else
        {
            strcpy(string, expression(expr->children, false, true));
            strcpy(string2, expression(expr->children->next, false, true));
            printf("%%%d = sub %s %s, %s\n", num_registo, var_type(expr->annotation), string, string2);
            sprintf(value, "%%%d", num_registo++);
            if (to_double)
            {
                i32_to_double(value);
            }
            else if (!to_i32)
            {
                i32_to_i1(value);
            }
            return strdup(value);
        }
    }
    else if (strcmp(expr->type, "Mul") == 0)
    {
        if (strcmp(expr->annotation, "double") == 0)
        {
            strcpy(string, expression(expr->children, true, false));
            strcpy(string2, expression(expr->children->next, true, false));
            printf("%%%d = fmul %s %s, %s\n", num_registo, var_type(expr->annotation), string, string2);
            sprintf(value, "%%%d", num_registo++);
            return strdup(value);
        }
        else
        {
            strcpy(string, expression(expr->children, false, true));
            strcpy(string2, expression(expr->children->next, false, true));
            printf("%%%d = mul %s %s, %s\n", num_registo, var_type(expr->annotation), string, string2);
            sprintf(value, "%%%d", num_registo++);
            if (to_double)
            {
                i32_to_double(value);
            }
            else if (!to_i32)
            {
                i32_to_i1(value);
            }
            return strdup(value);
        }
    }
    else if (strcmp(expr->type, "Div") == 0)
    {
        if (strcmp(expr->annotation, "double") == 0)
        {
            strcpy(string, expression(expr->children, true, false));
            strcpy(string2, expression(expr->children->next, true, false));
            //divisao de floats
            printf("%%%d = fdiv %s %s, %s\n", num_registo, var_type(expr->annotation), string, string2);
            sprintf(value, "%%%d", num_registo++);
            return strdup(value);
        }
        else
        {
            strcpy(string, expression(expr->children, false, true));
            strcpy(string2, expression(expr->children->next, false, true));
            printf("%%%d = sdiv %s %s, %s\n", num_registo, var_type(expr->annotation), string, string2);
            sprintf(value, "%%%d", num_registo++);
            if (to_double)
            {
                i32_to_double(value);
            }
            else if (!to_i32)
            {
                i32_to_i1(value);
            }
            return strdup(value);
        }
    }
    else if (strcmp(expr->type, "Mod") == 0)
    {
        if (strcmp(expr->annotation, "double") == 0)
        {
            strcpy(string, expression(expr->children, true, false));
            strcpy(string2, expression(expr->children->next, true, false));
            printf("%%%d = frem %s %s, %s\n", num_registo, var_type(expr->annotation), string, string2);
            sprintf(value, "%%%d", num_registo++);
            return strdup(value);
        }
        else
        {
            strcpy(string, expression(expr->children, false, true));
            strcpy(string2, expression(expr->children->next, false, true));
            printf("%%%d = srem %s %s, %s\n", num_registo, var_type(expr->annotation), string, string2);
            sprintf(value, "%%%d", num_registo++);
            if (to_double)
            {
                i32_to_double(value);
            }
            else if (!to_i32)
            {
                i32_to_i1(value);
            }
            return strdup(value);
        }
    }
    else if (strcmp(expr->type, "Comma") == 0 || strcmp(expr->type, "RealComma") == 0)
    {
        expression(expr->children, false, false);

        if (strcmp(expr->annotation, "double") == 0)
        {
            strcpy(value, expression(expr->children->next, true, false));
            return strdup(value);
        }
        else
        {
            strcpy(value, expression(expr->children->next, false, true));

            if (to_double)
            {
                i32_to_double(value);
            }
            else if (!to_i32)
            {
                i32_to_i1(value);
            }

            return strdup(value);
        }
    }

    return NULL;
}

char *var_type(char *type)
{
    //IF PARA SABER O TIPO DA FUNCAO!
    if (strcmp(type, "int") == 0 || strcmp(type, "char") == 0 || strcmp(type, "short") == 0 || strcmp(type, "Int") == 0 || strcmp(type, "Char") == 0 || strcmp(type, "Short") == 0)
    {
        return ("i32");
    }
    else if (strcmp(type, "void") == 0 || strcmp(type, "Void") == 0)
    {
        //nao sei ainda o q e suposto imprimir
        return ("void");
    }
    //DOUBLE
    else
    {
        return ("double");
    }
}

int size(char *type)
{
    //IF PARA SABER O TIPO DA FUNCAO!
    if (strcmp(type, "int") == 0 || strcmp(type, "char") == 0 || strcmp(type, "short") == 0 || strcmp(type, "Int") == 0 || strcmp(type, "Char") == 0 || strcmp(type, "Short") == 0)
    {
        return 4;
    }
    //DOUBLE
    else
    {
        return 8;
    }
}

void declaration(program *node, bool global)
{
    //node                          é Declaration
    //node->children                é char/int/double
    //node->children->next          é id
    //node->children->next->next    é o valor
    //printf("%s\n", node->children->next->next->type);
    char type[10], expr[50];

    strcpy(type, var_type(node->children->type));

    if (global)
    {
        if (node->children->next->next)
        {
            if (strcmp(node->children->type, "Double") == 0)
            {
                printf("@%s = global %s 0.0, align %d\n", node->children->next->children->type, type, size(node->children->type));
            }
            else
            {
                printf("@%s = global %s 0, align %d\n", node->children->next->children->type, type, size(node->children->type));
            }
            insert_global_var(node->children, strdup(node->children->next->children->type));
        }
        else
        {
            printf("@%s = global %s 0, align %d\n", node->children->next->children->type, type, size(node->children->type));
        }
    }
    else
    {
        printf("%%%s = alloca %s, align %d\n", node->children->next->children->type, type, size(node->children->type));

        if (node->children->next->next)
        {
            //tmb temos um valor para guardar
            if (strcmp(node->children->type, "Double") == 0)
            {
                strcpy(expr, expression(node->children->next->next, true, false));
                print_tab(tab_indent);
                printf("store %s %s, %s* %%%s\n", type, expr, type, node->children->next->children->type);
            }
            else
            {
                strcpy(expr, expression(node->children->next->next, false, true));
                print_tab(tab_indent);
                printf("store %s %s, %s* %%%s\n", type, expr, type, node->children->next->children->type);
            }
        }
    }
}

int charlit_to_int(char *string)
{
    if (strlen(string) == 3)
    {
        //char normal 'A'
        return string[1];
    }
    else if (strcmp("'\\n'", string) == 0)
    {
        return '\n';
    }
    else if (strcmp("'\\t'", string) == 0)
    {
        return '\t';
    }
    else if (strcmp("'\\\\'", string) == 0)
    {
        return '\\';
    }
    else if (strcmp("'\\''", string) == 0)
    {
        return '\'';
    }
    else if (strcmp("'\\\"'", string) == 0)
    {
        return '\"';
    }
    else if (strlen(string) == 4)
    {
        // '\0'
        return string[2] - 48;
    }
    else if (strlen(string) == 5)
    {
        // '\00'
        return 8 * (string[2] - 48) + (string[3] - 48);
    }
    else
    {
        // '\000'
        // '0' - 48 = 0
        return 64 * (string[2] - 48) + 8 * (string[3] - 48) + (string[4] - 48);
    }
}

int intlit_to_int(char *string)
{
    int value;
    sscanf(string, "%d", &value);
    return value;
}

void print_tab(int local_indent)
{
    for (int i = 0; i < local_indent; i++)
        printf("\t");
}

void i32_to_double(char *value)
{
    print_tab(tab_indent);
    sprintf(value, "%%%d", num_registo++);
    printf("%s = sitofp i32 %%%d to double\n", value, num_registo - 2);
}

void i1_to_i32(char *value)
{
    print_tab(tab_indent);
    sprintf(value, "%%%d", num_registo++);
    printf("%s = zext i1 %%%d to i32\n", value, num_registo - 2);
}

void i1_to_double(char *value)
{
    print_tab(tab_indent);
    sprintf(value, "%%%d", num_registo++);
    printf("%s = sitofp i1 %%%d to double\n", value, num_registo - 2);
}

void i32_to_i1(char *value)
{
    print_tab(tab_indent);
    sprintf(value, "%%%d", num_registo++);
    printf("%s = trunc i32 %%%d to i1\n", value, num_registo - 2);
}

void check_gen_while(program *node)
{
    char *value;
    int current_while = while_num++;
    bool has_return;
    printf("br label %%while-%d\n", current_while);

    //expressao
    printf("\nwhile-%d:\n", current_while);
    value = expression(node->children, false, false);

    printf("br i1 %s, label %%whilebody-%d, label %%whileafter-%d\n", value, current_while, current_while);

    //body
    printf("\nwhilebody-%d:\n", current_while);
    has_return = function_body(node->children->next);
    if (!has_return)
    {
        printf("br label %%while-%d\n", current_while);
    }

    printf("\nwhileafter-%d:\n", current_while);
}

void check_gen_if(program *node)
{
    char *value;
    int current_if = if_num++;
    bool has_return;

    //expressao
    value = expression(node->children, false, true);
    printf("%%%d = icmp ne i32 %s, 0\n", num_registo, value);
    printf("br i1 %%%d, label %%iftrue-%d, label %%iffalse-%d\n", num_registo++, current_if, current_if);

    printf("\niftrue-%d:\n", current_if);
    has_return = function_body(node->children->next);
    if (!has_return)
    {
        printf("br label %%ifafter-%d\n", current_if);
    }

    printf("\niffalse-%d:\n", current_if);
    has_return = function_body(node->children->next->next);
    if (!has_return)
    {
        printf("br label %%ifafter-%d\n", current_if);
    }

    printf("\nifafter-%d:\n", current_if);
}

void insert_global_var(struct _s1 *node, char *var_name)
{
    global_var_expression *new = (global_var_expression *)malloc(sizeof(global_var_expression));
    new->next = NULL;
    new->node = node;
    new->var_name = strdup(var_name);

    if (!global_var_list)
    {
        global_var_list = new;
        return;
    }

    global_var_expression *aux = global_var_list;
    while (aux->next)
    {
        aux = aux->next;
    }

    aux->next = new;
}

void initialize_global_vars(void)
{
    global_var_expression *aux = global_var_list;
    char expr[50];
    if (aux)
    {
        while (aux)
        {
            //tmb temos um valor para guardar
            if (strcmp(aux->node->type, "Double") == 0)
            {
                strcpy(expr, expression(aux->node->next->next, true, false));
                printf("store double %s, double* @%s\n", expr, aux->var_name);
            }
            else
            {
                strcpy(expr, expression(aux->node->next->next, false, true));
                printf("store i32 %s, i32* @%s\n", expr, aux->var_name);
            }

            aux = aux->next;
        }
    }
}