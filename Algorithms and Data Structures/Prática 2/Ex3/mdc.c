#include <stdio.h>
#include <locale.h>
#include "mdc.h"

void mdc(int x, int y) {

    setlocale(LC_ALL, "");

    int div;

    for(int i=1; i<=x && i<=y; i++)  {
        if(x%i==0 && y%i==0)
            div=i;
    }

    printf("O MDC desses dois números é %d.", div);
}