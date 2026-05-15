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

    FILE *fp = fopen("arq.txt", "r");
    if(fp==NULL)  {
        printf("Erro ao abrir o arquivo.");
        return 1;
    }

    Produto P;

    while(fscanf(fp, " %d; %9[^;]; %f; %d",
            &P.codProd,
            P.nomeProd,
            &P.valor,
            &P.qtdeEstoque) ==4)   {
                
                insereprod(lp, P, &size);
                printf("Código do produto: %d.\n", P.codProd);
                printf("Nome do produto: %s.\n", P.nomeProd);
                printf("Valor do produto: %.2f.\n", P.valor);
                printf("Quantidade em estoque: %d.\n\n", P.qtdeEstoque);
            }

    cheaper(lp);
    
    fclose(fp);

    int option, q, w;
    printf("Você deseja comprar algum produto? Digite 1 para sim e 2 para não.");
    scanf("%d", &option);

    if(option==1)  {
        printf("Digite o código do produto: ");
        scanf("%d", &w);
        printf("\nDigite quantas unidades do produto voce deseja comprar: ");
        scanf("%d", &q);
        venda(lp, q, w);
    }
        else if(option==2)  {
            printf("Agradecemos sua visita!");
        }
        else
            printf("Numero invalido.");

    return 0;
}