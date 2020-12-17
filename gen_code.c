#include "gen_code.h"

int num_registo, tab_indent = 0;

void start_program(program *prog)
{
    program *my_program;
    if (strcmp(prog->type, "Program") == 0)
    {
        my_program = prog->children;
    }
    else
    {
        my_program = prog;
    }

    while (my_program)
    {
        //printf("\n\nNEW FUNCTION\n\n");
        //printf("%s\n", prog->type);

        //ACHO Q ISTO NAO VAI SER PRECISO
        /*else if(strcmp(my_program->type, "RealComma") == 0){
            printf(", ");
            if(my_program->children)
                print_ast_noted(my_program->children);
        }*/
        //printf("                        %s\n", my_program->type);
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
        }

        /*if(my_program->children){
            ;
        }*/
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
    num_registo = 0;
    char string[50];

    while (body)
    {
        print_tab(tab_indent);

        //Store
        if (strcmp(body->type, "Store") == 0)
        {
            printf("Store\n");
            *(body->children->children->type) = tolower(*(body->children->children->type));
            printf("%%%s = %s %s\n", body->children->children->type, var_type(body->children->next->annotation), body->children->next->children->type);
        }
        //Declaration
        if (strcmp(body->type, "Declaration") == 0)
        {
            declaration(body);
        }
        //Return
        else if (strcmp(body->type, "Return") == 0)
        {
            print_tab(tab_indent);
            strcpy(string, expression(body->children));

            printf("ret %s %s\n", var_type(body->children->annotation), string);
            //FALTAM MERDAS(ainda nao sei bem cm fazer pq pode chamar declaraçao de funcao, soma, sub, mod......)
        }
        else if (strcmp(body->type, "Call") == 0)
        {
            printf("Call\n");
        }
        else if (strcmp(body->type, "If") == 0)
        {
            printf("If\n");
        }
        else if (strcmp(body->type, "While") == 0)
        {
            printf("While\n");
        }

        body = body->next;
    }
}

char *expression(program *expr)
{
    char value[VALUE_SIZE];

    if (strcmp(expr->type, "ChrLit") == 0)
    {
        sprintf(value, "%d", charlit_to_int(expr->children->type));
        return strdup(value);
    }
    else if (strcmp(expr->type, "IntLit") == 0)
    {
        sprintf(value, "%s", expr->children->type);
        return strdup(value);
    }
    else if (strcmp(expr->type, "Id") == 0)
    {
        printf("Id");
        //printf("%%%s = add %s 0, %%%s\n", node->children->next->children->type, var_type(node->children->type), expr->children->type);
    }

    else if (strcmp(expr->type, "Store") == 0)
    {
        printf("Store\n");
        //printf("%%%s", body->children->type);
    }

    else if (strcmp(expr->type, "Call") == 0)
    {
        // call i32 @sum(i32 1, i32 2, i32 3)
        printf("call\n");
    }
    else if (strcmp(expr->type, "Or") == 0)
    {
        printf("Or\n");
    }
    else if (strcmp(expr->type, "And") == 0)
    {
        printf("And\n");
    }
    else if (strcmp(expr->type, "BitwiseAnd") == 0)
    {
        printf("BitWiseAnd");
    }
    else if (strcmp(expr->type, "BitwiseOr") == 0)
    {
        printf("BitwiseOr\n");
    }
    else if (strcmp(expr->type, "BitwiseXor") == 0)
    {
        printf("BitwiseXor\n");
    }

    else if (strcmp(expr->type, "Eq") == 0)
    {
        printf("Eq\n");
    }
    else if (strcmp(expr->type, "Ne") == 0)
    {
        printf("Ne\n");
    }
    else if (strcmp(expr->type, "Le") == 0)
    {
        printf("Le\n");
    }
    else if (strcmp(expr->type, "Ge") == 0)
    {
        printf("Ge\n");
    }
    else if (strcmp(expr->type, "Lt") == 0)
    {
        printf("Lt\n");
    }
    else if (strcmp(expr->type, "Gt") == 0)
    {
        printf("Gt\n");
    }
    else if (strcmp(expr->type, "Not") == 0)
    {
        printf("Not\n");
    }
    else if (strcmp(expr->type, "Plus") == 0)
    {
        printf("Plus\n");
    }
    else if (strcmp(expr->type, "Minus") == 0)
    {
        printf("Minus\n");
    }
    else if (strcmp(expr->type, "Add") == 0)
    {
        printf("%%%d = add %s %s %s\n", num_registo, var_type(expr->annotation), expression(expr->children), expression(expr->children->next));
        sprintf(value, "%%%d", num_registo++);
        return strdup(value);
    }
    else if (strcmp(expr->type, "Sub") == 0)
    {
        printf("Sub\n");
    }
    else if (strcmp(expr->type, "Mul") == 0)
    {
        printf("Mul\n");
    }
    else if (strcmp(expr->type, "Div") == 0)
    {
        printf("Div\n");
    }
    else if (strcmp(expr->type, "Mod") == 0)
    {
        printf("Mod\n");
    }

    print_tab(tab_indent);
}

char *var_type(char *type)
{
    //IF PARA SABER O TIPO DA FUNCAO!
    if (strcmp(type, "int") == 0 || strcmp(type, "char") == 0 || strcmp(type, "short") == 0 || strcmp(type, "Int") == 0 || strcmp(type, "Char") == 0 || strcmp(type, "Short") == 0)
    {
        return ("i32");
    }
    else if (strcmp(type, "void") == 0 || strcmp(type, "Void"))
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
    printf("%%%s = alloca %s, allign %d\n", node->children->next->children->type, type, size(node->children->type));

    if (node->children->next->next)
    {
        //tmb temos um valor para guardar
        print_tab(tab_indent);
        strcpy(expr, expression(node->children->next->next));

        print_tab(tab_indent);
        printf("store %s %s, %s* %%%s\n", var_type(node->children->next->next->annotation), expr, type, node->children->next->children->type);
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