#include <stdio.h>
#include <stdlib.h>
#include "bib.h"

// Inicia a lista com um tamanho fixo (capacidade)
void iniciar(ListaDinamica *l, int capacidade) {
    l->elementos = (int *)malloc(capacidade * sizeof(int));
    l->tamanho = 0;
    l->capacidade = capacidade;
}

void inserir(ListaDinamica *l, int x)  {
    if(l->tamanho < l->capacidade)  {
        l->elementos[l->tamanho] = x;
        l->tamanho++;
    }
    else  {
        int newcap = l->capacidade+1;
        int *temp= (int*)realloc(l->elementos, newcap*sizeof(int));
        if(temp != NULL) {
            l->elementos = temp;
            l->elementos[l->tamanho] = x;
            l->capacidade = newcap;
            l->tamanho++;
        }
            else {
                printf("Memoria insuficiente.\n");
            }
    }
}

void exibir(ListaDinamica *l)  {
    for(int i=0; i<l->tamanho; i++)  {
        printf("%d ", l->elementos[i]);
    }
}

void liberar(ListaDinamica *l)  {
    free(l->elementos);
}