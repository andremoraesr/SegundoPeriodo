#include <stdio.h>
#include <locale.h>
#include "mdc.h"

int main()  {

    setlocale(LC_ALL, "");

    int x, y;

    printf("Digite dois números: ");
    scanf("%d %d", &x, &y);

    mdc(x, y);

    return 0;
}