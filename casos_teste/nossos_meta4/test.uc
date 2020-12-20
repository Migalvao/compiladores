int fausto(int a){
    return a;
}

int b(void){
    return 0;
}


int main(void){
    int a = 5;
    while(a);

    while(!a);

    while(+a);
    while(-a);

    double d = 1.5;
    double c = d*2;

    while(5);
    while('c');

    while(a = a = 5);
    while(fausto(10));
    while(b());

    while(a || 10);
    while(a && 10);
    while(a & 10);
    while(a | 10);
    while(a ^ 10);

    while(10 + 5);
    while(10 - 5);
    while(10 * 5);
    while(10 / 5);
    while(10 % 5);

    while(a, a);
}