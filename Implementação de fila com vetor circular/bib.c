#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "bib.h"

struct fila{
    int capacidade;
    double *itens;
    int inicio, fim;
    int quantidade;
};

Fila *criarFila(int x) {
    Fila *f;
    f = (Fila*)malloc(sizeof(Fila));
    f->capacidade = x;
    f->inicio = 0;
    f->fim = -1;
    f->quantidade = 0;
    f->itens = (double*)malloc(f->capacidade * sizeof(double));
    return f;
}

int full(Fila *f) {
    return (f->capacidade == f->quantidade);
}

void enfileira(Fila *f, double y) {
    setlocale(LC_ALL, "");

    if(full(f)) {
        printf("\nA fila está cheia.\n");
        return;
    }
    
    if (f->fim == f->capacidade-1){
        f->fim = -1;
    }

    f->fim++;
    f->itens[f->fim] = y;
    f->quantidade++;
}

int empty(Fila *f) {
    return(f->quantidade == 0);
}

double desenfileirar(Fila *f) {
    setlocale(LC_ALL, "");

    if(f->inicio == f->capacidade-1) {
        f->inicio = 0;
    }
    double temp = f->itens[f->inicio];
    f->quantidade--;
    f->inicio++;
    return temp;
}

int quant(Fila *f) {
    return f->quantidade;
}

void percorre(Fila *f) {
    if(empty(f)) 
    {
        printf("\nA fila está vazia.\n");
    }
    else {
        if(f->inicio < f->fim) 
        {
            for(int i=f->inicio; i<=f->fim; i++) 
            {
                printf("%lf  ", f->itens[i]);
            }
        }
        else {
            for(int i=f->inicio; i<f->capacidade; i++) 
            {
                printf("%lf  ", f->itens[i]);
            }
            for(int j=0; j<=f->fim; j++) 
            {
                printf("lf  ", f->itens[j]);
            }
        }
    }
}

void libera(Fila *f) {
    free(f->itens);
    free(f);
}