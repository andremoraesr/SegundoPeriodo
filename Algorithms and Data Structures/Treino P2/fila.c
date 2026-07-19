#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

struct software {
    char titulo[25];
    char autor [50];
    int ano;
    char linguagem[15];
    struct software *ant;
    struct software *prox;
};

struct fila {
    struct software *fim;
};


Fila *iniciaFila() {
    Fila *f;
    f = (Fila*)malloc(sizeof(Fila));
    if (f!=NULL) {
        f->fim = NULL;
        return f;
    }
}

No *criarNo() {
    No *novo;
    novo = (No*)malloc(sizeof(No));
    if(novo != NULL) {
        novo->ant = NULL;
        novo->prox = NULL;
        return novo;
    }
}

void insere(Fila *f, char *nome, char *titulo, char *linguagem, int ano) {
    No *novo = criarNo();
    novo->ano = ano;
    strcpy(novo->autor, nome);
    strcpy(novo->linguagem, linguagem);
    strcpy(novo->titulo, titulo);
    if(f->fim->prox == NULL) {
        f->fim->prox = novo;
        f->fim = novo;
        novo->ant = f->fim;
        novo->prox = novo;
    }
    else {
        novo->prox = f->fim->prox;
        novo->prox->ant = novo;
        novo->ant = f->fim->ant;
        f->fim->prox = novo;
        f->fim = novo;
    }
}

void remove(Fila *f) {
    No *aux = f->fim->prox;

    if(f->fim->prox == f->fim) {
        free(aux);
        f->fim = NULL;
    }
    else {
        f->fim->prox = aux->prox;
        aux->prox->ant = f->fim;
        free(aux);
    }
}