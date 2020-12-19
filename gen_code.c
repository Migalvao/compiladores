#include "gen_code.h"

int num_registo, tab_indent = 0, if_num, while_num;
table *function_table = NULL;

void start_program(program *prog)
{
    program *my_program = prog->children;

    printf("declare i32 @putchar(i32 nocapture) nounwind\n");

    while (my_program)
    {
        if (strcmp(my_program->type, "FuncDefinition") == 0)
        {
            function_def(my_program);
        }
        else if (strcmp(my_program->type, "FuncDeclaration") == 0)
        {
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
    printf("define %s @%s(", var_type(node->children->type), node->children->next->children->type);

    sprintf(table_name, "Function %s", node->children->next->children->type);
    function_table = search_table(table_name);

    if (strcmp(node->children->next->next->type, "ParamList") == 0)
    {
        param = node->children->next->next->children;
        //Este if ve se existe parametros ou nao na funcao (node->children->next->next->children->children->type = tipo de parametro)
        if (strcmp(node->children->next->next->children->children->type, "Void") == 0)
        {
            //printf("via");
            printf(") {\n");
        }
        else
        {
            printf("%s %s", var_type(param->children->type), param->children->next->type);

            param = param->next;

            if (param)
            {
                while (param)
                {
                    printf(", %s %s", var_type(param->children->type), param->children->next->type);
                    param = param->next;
                }
            }

            printf(") {\n");
        }
    }

    tab_indent++;
    function_body(node->children->next->next->next);

    printf("}");
}

void function_dec(program *node)
{
    program *param;
    //DECLARAÇAO DE FUNCAO
    printf("define %s @%s(", var_type(node->children->type), node->children->next->children->children->type);

    if (strcmp(node->children->next->next->type, "ParamList") == 0)
    {
        param = node->children->next->next->children;
        //Este if ve se existe parametros ou nao na funcao (node->children->next->next->children->children->type = tipo de parametro)
        if (strcmp(node->children->next->next->children->children->type, "Void") == 0)
        {
            //printf("via");
            printf(") {\n");
        }
        else
        {
            printf("%s %s", var_type(param->children->type), param->children->next->type);

            param = param->next;

            if (param)
            {
                while (param)
                {
                    printf(", %s %s", var_type(param->children->type), param->children->next->type);
                    param = param->next;
                }
            }

            printf(") {\n");
        }
    }
}

void function_body(program *func_body)
{
    //printf("BODY\n");
    program *body;
    bool single_statement = false;
    char string[100], string2[200], params[400];

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

    if (strcmp(func_body->type, "FuncBody") == 0)
    {
        num_registo = if_num = while_num = 1;
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
            //TODO verificar tipo
            strcpy(string, expression(body->children, false, false));

            print_tab(tab_indent);
            printf("ret %s %s\n", var_type(body->children->annotation), string);
        }
        else if (strcmp(body->type, "Call") == 0)
        {
            if (body->children->next)
            {
                program *param;
                param = body->children->next;

                strcpy(string, expression(param, false, false));
                sprintf(params, "%s %s", var_type(param->annotation), string);

                if (param->next)
                {
                    param = param->next;
                    while (param)
                    {
                        strcpy(string, expression(param, false, false));
                        sprintf(string2, ", %s %s", var_type(param->annotation), string);
                        strcat(params, string2);

                        param = param->next;
                    }
                }
            }
            if (strcmp(body->annotation, "void") != 0)
                printf("%%%d = call %s @%s(%s)\n", num_registo++, var_type(body->annotation), body->children->children->type, params);
            else
                printf("call %s @%s(%s)\n", var_type(body->annotation), body->children->children->type, params);
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
            return;
        body = body->next;
    }
}

char *expression(program *expr, bool to_double, bool to_i32)
{
    char value[VALUE_SIZE], string[100], params[300];

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
        sprintf(value, "%s", expr->children->type);
        return strdup(value);
    }
    else if (strcmp(expr->type, "Id") == 0)
    {
        if (function_table && search_variable(expr->children->type, function_table))
        {
            //variavel local
            printf("%%%d = load %s, %s* %%%s\n", num_registo, var_type(expr->annotation), var_type(expr->annotation), expr->children->type);
            sprintf(value, "%%%d", num_registo++);
        }
        else
        {
            //variavel global
            printf("%%%d = load %s, %s* @%s\n", num_registo, var_type(expr->annotation), var_type(expr->annotation), expr->children->type);
            sprintf(value, "%%%d", num_registo++);
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
        if (function_table && search_variable(expr->children->type, function_table))
            printf("store %s %s, %s* %%%s\n", var_type(expr->annotation), value, var_type(expr->children->annotation), expr->children->children->type);
        else
            printf("store %s %s, %s* @%s\n", var_type(expr->annotation), value, var_type(expr->children->annotation), expr->children->children->type);

        if (to_double)
        {
            sprintf(value, "%s", expression(expr->children->next, true, false));
        }

        return strdup(value);
    }

    else if (strcmp(expr->type, "Call") == 0)
    {
        if (expr->children->next)
        {
            program *param;
            param = expr->children->next;

            strcpy(value, expression(param, false, false));
            sprintf(params, "%s %s", var_type(param->annotation), value);

            if (param->next)
            {
                param = param->next;
                while (param)
                {
                    strcpy(value, expression(param, false, false));
                    sprintf(string, ", %s %s", var_type(param->annotation), value);
                    strcat(params, string);
                    param = param->next;
                }
            }
        }

        if (strcmp(expr->annotation, "void") != 0)
        {
            printf("%%%d = call %s @%s(%s)\n", num_registo, var_type(expr->annotation), expr->children->children->type, params);
            sprintf(value, "%%%d", num_registo++);
            return strdup(value);
        }
        else
        {
            printf("RETURN VOID?\n");
            return NULL;
        }
    }
    else if (strcmp(expr->type, "Or") == 0)
    {
        printf("%%%d = or %s %s, %s\n", num_registo, var_type(expr->annotation), expression(expr->children, false, false), expression(expr->children->next, false, false));
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
    else if (strcmp(expr->type, "And") == 0)
    {
        printf("%%%d = and %s %s, %s\n", num_registo, var_type(expr->annotation), expression(expr->children, false, false), expression(expr->children->next, false, false));
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
    else if (strcmp(expr->type, "BitWiseAnd") == 0)
    {
        printf("%%%d = and %s %s, %s\n", num_registo, var_type(expr->annotation), expression(expr->children, false, false), expression(expr->children->next, false, false));
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
    else if (strcmp(expr->type, "BitWiseOr") == 0)
    {
        printf("%%%d = or %s %s, %s\n", num_registo, var_type(expr->annotation), expression(expr->children, false, false), expression(expr->children->next, false, false));
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
    else if (strcmp(expr->type, "BitWiseXor") == 0)
    {
        printf("%%%d = xor %s %s, %s\n", num_registo, var_type(expr->annotation), expression(expr->children, false, false), expression(expr->children->next, false, false));
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

    else if (strcmp(expr->type, "Eq") == 0)
    {
        printf("%%%d = icmp eq %s %s, %s\n", num_registo, var_type(expr->annotation), expression(expr->children, false, false), expression(expr->children->next, false, false));
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
        printf("%%%d = icmp ne %s %s, %s\n", num_registo, var_type(expr->annotation), expression(expr->children, false, false), expression(expr->children->next, false, false));
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
        printf("%%%d = icmp sle %s %s, %s\n", num_registo, var_type(expr->annotation), expression(expr->children, false, false), expression(expr->children->next, false, false));
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
        printf("%%%d = icmp sge %s %s, %s\n", num_registo, var_type(expr->annotation), expression(expr->children, false, false), expression(expr->children->next, false, false));
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
        printf("%%%d = icmp slt %s %s, %s\n", num_registo, var_type(expr->annotation), expression(expr->children, false, false), expression(expr->children->next, false, false));
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
        printf("%%%d = icmp sgt %s %s, %s\n", num_registo, var_type(expr->annotation), expression(expr->children, false, false), expression(expr->children->next, false, false));
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
        printf("Not\n");
        return NULL;
    }
    else if (strcmp(expr->type, "Plus") == 0)
    {
        if (strcmp(expr->annotation, "double") == 0)
        {
            printf("%%%d = fadd %s %s, 0.0\n", num_registo, var_type(expr->annotation), expression(expr->children, true, false));
            sprintf(value, "%%%d", num_registo++);
            return strdup(value);
        }
        else
        {
            printf("%%%d = add %s %s, 0\n", num_registo, var_type(expr->annotation), expression(expr->children, false, false));
            sprintf(value, "%%%d", num_registo++);
            if (to_double)
            {
                i32_to_double(value);
            }
            return strdup(value);
        }
    }
    else if (strcmp(expr->type, "Minus") == 0)
    {
        if (strcmp(expr->annotation, "double") == 0)
        {
            printf("%%%d = fsub %s 0.0, %s\n", num_registo, var_type(expr->annotation), expression(expr->children, true, false));
            sprintf(value, "%%%d", num_registo++);
            return strdup(value);
        }
        else
        {
            printf("%%%d = sub %s 0, %s\n", num_registo, var_type(expr->annotation), expression(expr->children, false, false));
            sprintf(value, "%%%d", num_registo++);
            if (to_double)
            {
                i32_to_double(value);
            }
            return strdup(value);
        }
    }
    else if (strcmp(expr->type, "Add") == 0)
    {
        if (strcmp(expr->annotation, "double") == 0)
        {
            printf("%%%d = fadd %s %s, %s\n", num_registo, var_type(expr->annotation), expression(expr->children, true, false), expression(expr->children->next, true, false));
            sprintf(value, "%%%d", num_registo++);
            return strdup(value);
        }
        else
        {
            printf("%%%d = add %s %s, %s\n", num_registo, var_type(expr->annotation), expression(expr->children, false, false), expression(expr->children->next, false, false));
            sprintf(value, "%%%d", num_registo++);
            if (to_double)
            {
                i32_to_double(value);
            }
            return strdup(value);
        }
    }
    else if (strcmp(expr->type, "Sub") == 0)
    {
        if (strcmp(expr->annotation, "double") == 0)
        {
            printf("%%%d = fsub %s %s, %s\n", num_registo, var_type(expr->annotation), expression(expr->children, true, false), expression(expr->children->next, true, false));
            sprintf(value, "%%%d", num_registo++);
            return strdup(value);
        }
        else
        {
            printf("%%%d = sub %s %s, %s\n", num_registo, var_type(expr->annotation), expression(expr->children, false, false), expression(expr->children->next, false, false));
            sprintf(value, "%%%d", num_registo++);
            if (to_double)
            {
                i32_to_double(value);
            }
            return strdup(value);
        }
    }
    else if (strcmp(expr->type, "Mul") == 0)
    {
        if (strcmp(expr->annotation, "double") == 0)
        {
            printf("%%%d = fmul %s %s, %s\n", num_registo, var_type(expr->annotation), expression(expr->children, true, false), expression(expr->children->next, true, false));
            sprintf(value, "%%%d", num_registo++);
            return strdup(value);
        }
        else
        {
            printf("%%%d = mul %s %s, %s\n", num_registo, var_type(expr->annotation), expression(expr->children, false, false), expression(expr->children->next, false, false));
            sprintf(value, "%%%d", num_registo++);
            if (to_double)
            {
                i32_to_double(value);
            }
            return strdup(value);
        }
    }
    else if (strcmp(expr->type, "Div") == 0)
    {
        if (strcmp(expr->annotation, "double") == 0)
        {
            //divisao de floats
            printf("%%%d = fdiv %s %s, %s\n", num_registo, var_type(expr->annotation), expression(expr->children, true, false), expression(expr->children->next, true, false));
            sprintf(value, "%%%d", num_registo++);
            return strdup(value);
        }
        else
        {
            printf("%%%d = sdiv %s %s, %s\n", num_registo, var_type(expr->annotation), expression(expr->children, false, false), expression(expr->children->next, false, false));
            sprintf(value, "%%%d", num_registo++);
            if (to_double)
            {
                i32_to_double(value);
            }
            return strdup(value);
        }
    }
    else if (strcmp(expr->type, "Mod") == 0)
    {
        if (strcmp(expr->annotation, "double") == 0)
        {
            printf("%%%d = frem %s %s, %s\n", num_registo, var_type(expr->annotation), expression(expr->children, true, false), expression(expr->children->next, true, false));
            sprintf(value, "%%%d", num_registo++);
            return strdup(value);
        }
        else
        {
            printf("%%%d = srem %s %s, %s\n", num_registo, var_type(expr->annotation), expression(expr->children, false, false), expression(expr->children->next, false, false));
            sprintf(value, "%%%d", num_registo++);
            if (to_double)
            {
                i32_to_double(value);
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
            //tmb temos um valor para guardar
            if (strcmp(node->children->type, "Double") == 0)
            {
                strcpy(expr, expression(node->children->next->next, true, false));
            }
            else
            {
                strcpy(expr, expression(node->children->next->next, false, true));
            }
            printf("@%s = global %s %s, align %d\n", node->children->next->children->type, type, expr, size(node->children->type));
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
        // \0
        return string[2] - 48;
    }
    else if (strlen(string) == 5)
    {
        // \00
        return 8 * (string[2] - 48) + (string[3] - 48);
    }
    else
    {
        // \000
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
    printf("%s = sext i32 %%%d to double\n", value, num_registo - 2);
}

void i1_to_i32(char *value)
{
    print_tab(tab_indent);
    sprintf(value, "%%%d", num_registo++);
    printf("%s = sext i1 %%%d to i32\n", value, num_registo - 2);
}

void i1_to_double(char *value)
{
    print_tab(tab_indent);
    sprintf(value, "%%%d", num_registo++);
    printf("%s = sext i1 %%%d to double\n", value, num_registo - 2);
}

void check_gen_while(program *node)
{
    char *value;
    int current_while = while_num++;
    printf("br label %%while-%d\n", current_while);

    //expressao
    printf("\nwhile-%d:\n", current_while);
    value = expression(node->children, false, false);

    printf("br i1 %s, label %%whilebody-%d, label %%whileafter-%d\n", value, current_while, current_while);

    //body
    printf("\nwhilebody-%d:\n", current_while);
    function_body(node->children->next);
    printf("br label %%while-%d\n", current_while);

    printf("\nwhileafter-%d:\n", current_while);
}

void check_gen_if(program *node)
{
    char *value;
    int current_if = if_num++;

    //expressao
    value = expression(node->children, false, false);
    printf("%%%d = icmp ne i32 %s, 0\n", num_registo, value);
    printf("br i1 %%%d, label %%iftrue-%d, label %%iffalse-%d\n", num_registo++, current_if, current_if);

    printf("\niftrue-%d:\n", current_if);
    function_body(node->children->next);
    printf("br label %%ifafter-%d\n", current_if);

    printf("\niffalse-%d:\n", current_if);
    function_body(node->children->next->next);
    printf("br label %%ifafter-%d\n", current_if);

    printf("\nifafter-%d:\n", current_if);
}