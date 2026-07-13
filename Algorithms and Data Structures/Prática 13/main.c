#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "bib.h"

int main () {
    setlocale(LC_ALL, "");

    Lista *l;
    criarListaVazia(&l);
    inserirPalavras(&l);
    ordenar(l);

    Pilha *p;
    iniciaPilha(&p);
    int option;
    char c;

    do {
        printf("\n1 - Procurar verbete.");
        printf("\n2 - Empilhar.");
        printf("\n3 - Desempilhar.");
        printf("\n0 - Sair.\n");
        scanf("%d", &option);
        switch (option) {
            case 1: {
                char nome[25];
                printf("\nDigite o verbete: ");
                while((c=getchar())!='\n'&&c!=EOF);
                scanf("%24[^\n]", nome);
                encontrar(l, nome);
                break;
            }
            case 2:
                leitura(p);
                break;
            case 3:
                desempilha(p, l);
                break;
            default:
                break;
        }
    } while (option != 0);

    libera(l);
    free(p);

    return 0;
}