#include <stdio.h>
#include <locale.h>
#include "all.h"

int main ()   {

    setlocale(LC_ALL, "");

    int n;

    printf("Digite o número N (até 100) que determina o tamanho de uma matriz NxN: ");
    scanf("%d", &n);

    int mat[n][n];

    printf("Agora digite os elementos dessa matriz: ");
    for(int i=0; i<n; i++)  {
        for(int j=0; j<n; j++)  {
            scanf("%d", &mat[i][j]);
        }
        setbuf(stdin, NULL);
    }
    printf("A soma dos elementos da matriz é: %d.\n", st(n, mat));
    printf("A soma dos elementos da diagonal principal é: %d.\n", sd(n, mat));
    printf("A soma dos elementos da diagonal secundária é: %d.\n", ss(n, mat));
    trans(n, mat);
    printf("\n");
    
    magica(n, mat);

    return 0;
}