#include <stdio.h>
#include <locale.h>
#include "all.h"

int st(int x, int mat[x][x])  {

    int soma=0;

    for(int i=0; i<x; i++)  {
        for(int j=0; j<x; j++)   {
            soma=soma+mat[i][j];
        }
    }
    return soma;
}

int sd(int x, int mat[x][x])  {

    int soma=0;

    for(int i=0; i<x; i++)  {
        for(int j=0; j<x; j++)   {
            if(i==j)
                soma=soma+mat[i][j];
        }
    }
    return soma;
}

int ss(int x, int mat[x][x])   {

    int soma=0;

    for(int i=0; i<x; i++)   {
        for(int j=x-1; j>=0; j--)   {
            if((i+j)==x-1)
                soma=soma+mat[i][j];
        }
    }
    return soma;
}

void trans(int x, int mat[x][x])   {

    int troca;

    for(int i=0; i<x; i++)   {
        for(int j=0; j<x; j++)  {
            printf("%d ", mat[j][i]);
        }
        printf("\n");
    }
}

void magica(int x, int mat[x][x])  {

    setlocale(LC_ALL, "");

    int pri=sd(x, mat);
    int sec=ss(x, mat);
    int somaL[x];
    int somaC[x];

    for(int i=0; i<x; i++)   {
        int soma=0;
        for(int j=0; j<x; j++)    {
            soma=soma+mat[i][j];
        }
        somaL[i]=soma;
    }
    for(int i=0; i<x; i++)   {
        int soma=0;
        for(int j=0; j<x; j++)    {
            soma=soma+mat[j][i];
        }
        somaC[i]=soma;
    }
    int i=0;
    while(i<x)  {
        if(somaL[i]==somaC[i] && pri==sec && somaL[i]==pri)   {
            printf("A matriz inserida é uma matriz quadrado mágico, e sua constante mágica é %d.", pri);
            break;
        }
            else   {
                printf("A matriz inserida não é um quadrado mágico!");
            }
        i++;
    }
}

