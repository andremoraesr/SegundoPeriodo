#include <stdio.h>
#include <stdlib.h>
#include "bib.h"
#include <locale.h>
#include <string.h>

int main() {

    setlocale(LC_ALL, "");

    No *l, *lp;
    criaListaVazia(&l);

    int option;
    char c;

    inserir(&l);

    do {
        printf("Menu de opçôes: \n");
        printf("Digite 1 para buscar uma palavra.\n");
        printf("Digite 2 para remover as palavras repetidas.\n");
        printf("Digite 3 para remover alguma palavra.\n");
        printf("Digite 4 para copiar a uma nova lista as palavras de tamanho primo.\n");
        printf("Digite 5 para descobrir quantas palavras há na lista.\n");
        printf("Digite 6 para ver as palavras da lista.\n");
        printf("Digite 0 para sair.\n");
        scanf("%d", &option);
        switch(option) {
            case 1: {
                while((c=getchar())!='\n'&&c!=EOF);
                char s1[30];
                printf("Qual palavra deseja buscar? ");
                scanf("%s", s1);
                busca(l, s1);
                break;
            }
            case 2:
                tirarepet(&l);
                printf("As repetidas foram removidas.\n\n");
                break;
            case 3: {
                char s2[30];
                while((c=getchar())!='\n'&&c!=EOF);
                printf("Qual palavra deseja remover? ");
                scanf("%s", s2);
                tiraUma(&l, s2);
                break;
            }
            case 4: {
                criaListaVazia(&lp);
                tiraprimos(l, &lp);
                break;
            }
            case 5:
                printf("A lista tem %d palavras.\n", quantasVezes(l));
                break;
            case 6: {
                printf("1 - Você quer ver a lista de todas as palavras.\n");
                printf("2 - Você quer ver a lista de palavras primas.\n");
                scanf("%d", &option);
                switch (option) {
                    case 1:
                        exibir(l);
                        break;
                    case 2:
                        exibir(lp);
                        break;
                    default:
                        break;
                }    
                break;
            }    
            default:
                break;
        }
    } while (option != 0);

    liberar(l);
    liberar(lp);

    return 0;
}