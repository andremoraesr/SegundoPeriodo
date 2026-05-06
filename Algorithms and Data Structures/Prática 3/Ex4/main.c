#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "ordena.h"

int main  ()   {

    setlocale(LC_ALL, "");

    int v[3];

    printf("Digite os 3 elementos: ");
    for(int i=0; i<3; i++)   {
        scanf("%d", &v[i]);
    }
    int *p;
    p= (int *) malloc(3*sizeof(int));

    printf("Os elementos em ordem são: ");
    ordena(v);

    free (p);

    return 0;
}