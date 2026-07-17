#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "bib.h"

int main() {

    setlocale(LC_ALL, "");

    Fila *fp;
    int cap;
    printf("Qual será a capacidade da fila?\n");
    scanf("%d", &cap);
    fp = criarFila(cap);

    int option;
    do {
        printf("\nMenu:");
        printf("\n1. Inserir elemento na fila.");
        printf("\n2. Remover elemento da fila.");
        printf("\n3. Mostrar quantidade de elementos enfileirados.");
        printf("\n4. Mostrar todos os elementos enfileirados.");
        printf("\n0. Sair.\n");
        scanf("%d", &option);
        switch (option) {
            case 1: {
                double x;
                printf("\nElemento a ser enfileirado: ");
                scanf("%lf", &x);
                enfileira(fp, x);
                break;
            }
            case 2: {
                if(empty(fp)) {
                    printf("\nA fila está vazia.\n");
                }
                else {
                    double fora = desenfileirar(fp);
                    printf("\nElemento removido: %lf", fora);
                    break;
                }
            }
            case 3:
                printf("\nQuantidade de elementos na fila: %d", quant(fp));
                break;
            case 4:
                percorre(fp);
                printf("\n");
                break;
            default:
                break;
        }
    } while (option != 0);

    libera(fp);

    return 0;
}