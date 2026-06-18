#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "bib.h"

struct nave {
    int cap;
    int nivel;
    int codigo;
    struct nave *prox;
};

struct lc {
    int quant;
    struct nave *inicio;
};

Listac *criarlistavazia() {
    Listac *l;
    l = (Listac*)malloc(sizeof(Listac));
    l->inicio = NULL;
    l->quant = 0;
    return l;
}

Nave *criarnave() {
    Nave *nova;
    nova = (Nave*)malloc(sizeof(Nave));
    if(nova != NULL) return nova;
}

void insere(Listac *l, int x, int y)  {
    Nave *nova;
    nova = criarnave();
    if (l->inicio == NULL) {
        nova->cap = x;
        nova->nivel = y;
        nova->prox = nova;
        l->inicio = nova;
        l->quant++;
        nova->codigo = l->quant;
    }
    else {
        nova->cap = x;
        nova->nivel = y;
        Nave *atual = l->inicio;
        while (atual->prox != l->inicio) {
            atual = atual->prox;
        }
        atual->prox = nova;
        nova->prox = l->inicio;
        l->quant++;
        nova->codigo = l->quant;
    }
}

void ciclo (Listac *l, int a, int *ciclos) {
    Nave *atual = l->inicio;
    int flag = 0;
    if(l->inicio != NULL ) {
    do {
        if((atual->nivel+a) >= atual->cap) {
            atual->nivel = atual->cap;
        }
        else {
            flag = 1;
            atual->nivel = atual->nivel + a;
        }
        atual = atual->prox;
    } while (atual != l->inicio);
    }
    else { 
        printf("Lista vazia.\n");
        return;
    }
    
    (*ciclos)++;
    if(flag != 0) {
        ciclo(l, a, ciclos);
    }
}

void exibir(Listac *l) {
    setlocale(LC_ALL, "");

    Nave *atual;
    atual = l->inicio;
    do {
        printf("Nave %d:\n", atual->codigo);
        printf("Nivel de combustivel: %d litros.\n", atual->nivel);
        printf("Capacidade: %d.\n\n", atual->cap);
        atual = atual->prox;
    } while (atual != l->inicio);
}

void libera(Listac *l) {
    Nave *aux = l->inicio;
    do {
        Nave *atual = aux;
        aux = aux->prox;
        free(atual);
    } while (aux != l->inicio);

    free(l);
}