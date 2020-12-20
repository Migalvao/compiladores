void whileAndIfChains(void)
{

    //prints: ABC

    int a = 5;
    int b;
    while (a <= 10)
    {
        b = 1;
        if (b == 2)
        {
        }
        else
        {

            if (a == 7)
            {
                putchar('\n');
                putchar('A');
                putchar('B');
                putchar('C');
                putchar('\n');
            }
        }

        a = a + 1;
    }
}
