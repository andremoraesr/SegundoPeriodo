#include <stdio.h>
#include <locale.h>

int main ()  {

    setlocale(LC_ALL, "");

    int a=10, *x;
    double b=20.52, *y;
    char c='a', *z;

    printf("Antes da modificação: \n%d\n", a);
    printf("%lf\n", b);
    printf("%c\n", c);

    x=&a;
    y=&b;
    z=&c;

    *x=12;
    *y=20.90;
    *z='b';

    printf("Depois da modificação: \n%d\n", a);
    printf("%lf\n", b);
    printf("%c\n", c);

    return 0;
}