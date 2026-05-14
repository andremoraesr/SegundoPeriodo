#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "bib.h"

int main ()  {

    setlocale(LC_ALL, "");

    int size;

    printf("Digite quantos produtos serão inseridos num primeiro momento: ");
    scanf("%d", &size);

    Lista *lp = criarlista(size);

    FILE *fp = fopen("arq.txt", "r+");
    if(fp==NULL)  {
        printf("Erro ao abrir o arquivo.");
        return 1;
    }

    Produto P;

    while(fscanf(fp, "%d; %9[^;]; %d; %f",
            &P.codProd,
            P.nomeProd,
            &P.qtdeEstoque,
            &P.valor) ==4)   {
                
                insereprod(lp, P, size);
                printf("Código do produto: %d.\n", &P.codProd);
                printf("Nome do produto: %s.\n", P.nomeProd);
                printf("Quantidade em estoque: %d.\n", &P.qtdeEstoque);
                printf("Valor do produto: %f.\n\n", &P.valor);
            }





}