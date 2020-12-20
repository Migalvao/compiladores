//#include <stdio.h>

int global = 6 + 7;
int func(int a, int b);

int func(int a, int b)
{
    int ret = 2 * a + 8 / b;
    return ret;
}

int main(void)
{
    int a, b = 0;
    double d;

    //arithmetic
    a = 060 + 5; // 48 + 5 = '5'
    putchar(a);
    d = 5 + 5.1;
    a = 060 - 5; // 48 - 5 = '+'
    putchar(a);
    d = 5 - 5.1;
    a = 5 / 5;
    d = 5 / 5.1;
    a = 060 * 2;
    putchar(a); //48 * 2 = '`'
    d = 5 * 5.1;
    a = 5 % 5;
    //d = 5 % 5.1;  Erro semantico

    //relational
    a = 6 > 5;
    d = 6 > 5.1;
    a = 6 >= 5;
    d = 6 >= 5.1;
    a = 6 >= 5;
    a = 6 <= 5;
    d = 6 <= 5.1;
    a = 6 == 5;
    d = 6 == 5.1;
    a = 6 != 5;

    //logical
    a = a & b;
    a = a && b;
    a = a | b;
    a = a || b;
    a = a ^ b;
    a = a && b || a | b & a ^ b;
    a = 1;
    a = !a;
    //a = !d;   //Erro semantico

    a = func(20, 4); //a = 42 -> '*'
    putchar(a);
    a = getchar();

    return 0;
}