#include <stdio.h>
#include <stdlib.h>
#include "bib.h"
#include <locale.h>

struct no {
    int valor;
    No *prox;
};

struct desc {
    No *inicio;
    No *fim;
    int size;
};

Descritor *criarlista() {
    Descritor *d = (Descritor*)malloc(sizeof(Descritor));
    if(d!=NULL) {
        d->fim=NULL;
        d->inicio=NULL;
        d->size=0;
    }
    return d;
}

No *criarNo(){
    No *novoNo = (No*)malloc(sizeof(No*));
    if(novoNo != NULL) return novoNo;
}

void insereInicio(Descritor *d, int x) {
    No *novoNo;
    novoNo = criarNo();
    novoNo->valor=x;
    novoNo->prox = d->inicio;
    if(d->fim==NULL) {
        d->fim=novoNo;
    }
    d->inicio = novoNo;
    d->size++;
}

void insereFinal(Descritor *d, int x) {
    No *novo = criarNo();
    novo->valor = x;
    novo->prox = NULL;
    if(d->fim != NULL) {
        d->fim->prox = novo;
    }
    d->fim=novo;
    d->size++;
}

void removeInicio(Descritor *d){
    No *atual = d->inicio;
    d->inicio = d->inicio->prox;
    if(d->inicio == NULL) {
        d->fim = NULL;
    }
    free(atual);
    d->size--;
}

void removeFinal(Descritor *d) {
    No *atual = d->fim;
    if (d->fim == d->inicio) {
        d->fim = NULL;
        d->inicio = NULL;
    }
    else {
        No *aux = d->inicio;
        for(int i=1; i < d->size; i++) {
            aux = aux->prox;
        }
        d->fim = aux;
        d->fim->prox = NULL;
    }
    free(atual);
    d->size--;
}

void removeElem(Descritor *d, int x) {
    No *atual = d->inicio;
    int flag = 1;
    if(atual->valor == x) {
        removeInicio(d);
    }
    else if (d->fim->valor == x) {
        removeFinal(d);
    }
    else {
        if (d->inicio == d->fim) {
            d->inicio = NULL;
            d->fim = NULL;
        }
        else {
            while ((atual != NULL) && (atual->valor != x)) {
                if ((atual->valor != x) && (atual == d->fim)) {
                    flag = 0;
                    break;
                }
                atual = atual->prox;
            }
            No *aux = d->inicio;
            if (flag != 0) {
                while (aux->prox != atual) {
                    aux = aux->prox;
                }
            }
            else return;
            
            aux->prox = atual->prox;
            free(atual);
            d->size--;
        }
    }
}

void exibe(Descritor *d)  {
    No *atual = d->inicio;
    if((atual == NULL) && (d->fim == NULL)) {
        printf("%d", d->size);
    }
    else {
        while (atual != NULL) {
            printf("%d ", atual->valor);
            atual = atual->prox;
        }
        printf("\n%d\n", d->size);
    }
}