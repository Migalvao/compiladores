#include "gen_code.h"

int num_registo, tab_indent = 0;

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
            //declaraçao global
        }

        printf("\n}");
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
    printf("define %s @%s(", var_type(node->children->type), node->children->next->children->type);

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
    program *body = func_body->children;
    num_registo = 1;
    char string[100], string2[200], params[400];

    while (body)
    {
        print_tab(tab_indent);

        //Store
        if (strcmp(body->type, "Store") == 0)
        {
            if (strcmp(body->annotation, "double") == 0)
                strcpy(string, expression(body->children->next, true));
            else
                strcpy(string, expression(body->children->next, false));

            print_tab(tab_indent);
            printf("store %s %s, %s* %%%s\n", var_type(body->annotation), string, var_type(body->children->annotation), body->children->children->type);
        }
        //Declaration
        if (strcmp(body->type, "Declaration") == 0)
        {
            declaration(body);
        }
        //Return
        else if (strcmp(body->type, "Return") == 0)
        {
            //TODO verificar tipo
            strcpy(string, expression(body->children, false));

            print_tab(tab_indent);
            printf("ret %s %s\n", var_type(body->children->annotation), string);
        }
        else if (strcmp(body->type, "Call") == 0)
        {

            if (body->children->next)
            {
                program *param;
                param = body->children->next;

                strcpy(string, expression(param, false));
                sprintf(params, "%s %s", var_type(param->annotation), string);

                if (param->next)
                {
                    param = param->next;
                    while (param)
                    {
                        strcpy(string, expression(param, false));
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
            printf("If\n");
        }
        else if (strcmp(body->type, "While") == 0)
        {
            printf("While\n");
            check_gen_while(body);
        }

        body = body->next;
    }
}

char *expression(program *expr, bool to_double)
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
        printf("%%%d = load %s, %s* %%%s\n", num_registo, var_type(expr->annotation), var_type(expr->annotation), expr->children->type);
        sprintf(value, "%%%d", num_registo++);
        return strdup(value);
    }

    else if (strcmp(expr->type, "Store") == 0)
    {
        printf("store %s %s, %s* %%%s\n", var_type(expr->annotation), expression(expr->children->next, false), var_type(expr->children->annotation), expr->children->children->type);
        sprintf(value, "%s", expr->children->type);
        return strdup(value);
    }

    else if (strcmp(expr->type, "Call") == 0)
    {
        if (expr->children->next)
        {
            program *param;
            param = expr->children->next;

            strcpy(value, expression(param, false));
            sprintf(params, "%s %s", var_type(param->annotation), value);

            if (param->next)
            {
                param = param->next;
                while (param)
                {
                    strcpy(value, expression(param, false));
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
        printf("%%%d = or %s %s, %s\n", num_registo, var_type(expr->annotation), expression(expr->children, false), expression(expr->children->next, false));
        sprintf(value, "%%%d", num_registo++);
        return strdup(value);
    }
    else if (strcmp(expr->type, "And") == 0)
    {
        printf("%%%d = and %s %s, %s\n", num_registo, var_type(expr->annotation), expression(expr->children, false), expression(expr->children->next, false));
        sprintf(value, "%%%d", num_registo++);
        return strdup(value);
    }
    else if (strcmp(expr->type, "BitwiseAnd") == 0)
    {
        printf("%%%d = and %s %s, %s\n", num_registo, var_type(expr->annotation), expression(expr->children, false), expression(expr->children->next, false));
        sprintf(value, "%%%d", num_registo++);
        return strdup(value);
    }
    else if (strcmp(expr->type, "BitwiseOr") == 0)
    {
        printf("%%%d = or %s %s, %s\n", num_registo, var_type(expr->annotation), expression(expr->children, false), expression(expr->children->next, false));
        sprintf(value, "%%%d", num_registo++);
        return strdup(value);
    }
    else if (strcmp(expr->type, "BitwiseXor") == 0)
    {
        printf("%%%d = xor %s %s, %s\n", num_registo, var_type(expr->annotation), expression(expr->children, false), expression(expr->children->next, false));
        sprintf(value, "%%%d", num_registo++);
        return strdup(value);
    }

    else if (strcmp(expr->type, "Eq") == 0)
    {
        printf("%%%d = icmp eq %s %s, %s\n", num_registo, var_type(expr->annotation), expression(expr->children, false), expression(expr->children->next, false));
        sprintf(value, "%%%d", num_registo++);
        return strdup(value);
    }
    else if (strcmp(expr->type, "Ne") == 0)
    {
        printf("%%%d = icmp ne %s %s, %s\n", num_registo, var_type(expr->annotation), expression(expr->children, false), expression(expr->children->next, false));
        sprintf(value, "%%%d", num_registo++);
        return strdup(value);
    }
    else if (strcmp(expr->type, "Le") == 0)
    {
        printf("%%%d = icmp sle %s %s, %s\n", num_registo, var_type(expr->annotation), expression(expr->children, false), expression(expr->children->next, false));
        sprintf(value, "%%%d", num_registo++);
        return strdup(value);
    }
    else if (strcmp(expr->type, "Ge") == 0)
    {
        printf("%%%d = icmp sge %s %s, %s\n", num_registo, var_type(expr->annotation), expression(expr->children, false), expression(expr->children->next, false));
        sprintf(value, "%%%d", num_registo++);
        return strdup(value);
    }
    else if (strcmp(expr->type, "Lt") == 0)
    {
        printf("%%%d = icmp slt %s %s, %s\n", num_registo, var_type(expr->annotation), expression(expr->children, false), expression(expr->children->next, false));
        sprintf(value, "%%%d", num_registo++);
        return strdup(value);
    }
    else if (strcmp(expr->type, "Gt") == 0)
    {
        printf("%%%d = icmp sgt %s %s, %s\n", num_registo, var_type(expr->annotation), expression(expr->children, false), expression(expr->children->next, false));
        sprintf(value, "%%%d", num_registo++);
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
            printf("%%%d = fadd %s %s, 0\n", num_registo, var_type(expr->annotation), expression(expr->children, true));
            sprintf(value, "%%%d", num_registo++);
            return strdup(value);
        }
        else
        {
            printf("%%%d = add %s %s, 0\n", num_registo, var_type(expr->annotation), expression(expr->children, false));
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
            printf("%%%d = fsub %s 0, %s\n", num_registo, var_type(expr->annotation), expression(expr->children, true));
            sprintf(value, "%%%d", num_registo++);
            return strdup(value);
        }
        else
        {
            printf("%%%d = sub %s 0, %s\n", num_registo, var_type(expr->annotation), expression(expr->children, false));
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
            printf("%%%d = fadd %s %s, %s\n", num_registo, var_type(expr->annotation), expression(expr->children, true), expression(expr->children->next, true));
            sprintf(value, "%%%d", num_registo++);
            return strdup(value);
        }
        else
        {
            printf("%%%d = add %s %s, %s\n", num_registo, var_type(expr->annotation), expression(expr->children, false), expression(expr->children->next, false));
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
            printf("%%%d = fsub %s %s, %s\n", num_registo, var_type(expr->annotation), expression(expr->children, true), expression(expr->children->next, true));
            sprintf(value, "%%%d", num_registo++);
            return strdup(value);
        }
        else
        {
            printf("%%%d = sub %s %s, %s\n", num_registo, var_type(expr->annotation), expression(expr->children, false), expression(expr->children->next, false));
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
            printf("%%%d = fmul %s %s, %s\n", num_registo, var_type(expr->annotation), expression(expr->children, true), expression(expr->children->next, true));
            sprintf(value, "%%%d", num_registo++);
            return strdup(value);
        }
        else
        {
            printf("%%%d = mul %s %s, %s\n", num_registo, var_type(expr->annotation), expression(expr->children, false), expression(expr->children->next, false));
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
            printf("%%%d = fdiv %s %s, %s\n", num_registo, var_type(expr->annotation), expression(expr->children, true), expression(expr->children->next, true));
            sprintf(value, "%%%d", num_registo++);
            return strdup(value);
        }
        else
        {
            printf("%%%d = sdiv %s %s, %s\n", num_registo, var_type(expr->annotation), expression(expr->children, false), expression(expr->children->next, false));
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
            printf("%%%d = frem %s %s, %s\n", num_registo, var_type(expr->annotation), expression(expr->children, true), expression(expr->children->next, true));
            sprintf(value, "%%%d", num_registo++);
            return strdup(value);
        }
        else
        {
            printf("%%%d = srem %s %s, %s\n", num_registo, var_type(expr->annotation), expression(expr->children, false), expression(expr->children->next, false));
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

void declaration(program *node)
{
    //node                          é Declaration
    //node->children                é char/int/double
    //node->children->next          é id
    //node->children->next->next    é o valor
    //printf("%s\n", node->children->next->next->type);
    char type[10], expr[50];

    strcpy(type, var_type(node->children->type));
    printf("%%%s = alloca %s, align %d\n", node->children->next->children->type, type, size(node->children->type));

    if (node->children->next->next)
    {
        //tmb temos um valor para guardar
        if (strcmp(node->children->type, "Double") == 0)
        {
            strcpy(expr, expression(node->children->next->next, true));
            print_tab(tab_indent);
            printf("store %s %s, %s* %%%s\n", type, expr, type, node->children->next->children->type);
        }
        else
        {
            strcpy(expr, expression(node->children->next->next, false));
            print_tab(tab_indent);
            printf("store %s %s, %s* %%%s\n", type, expr, type, node->children->next->children->type);
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

void check_gen_while(program *node)
{
    char *value;
    printf("br label %%%d\n\n", num_registo++);

    printf("%d:\n", num_registo - 1);
    //expressao
    value = expression(node->children, false);

    //printf("br i1 %s, label piça, label kona\n");
}