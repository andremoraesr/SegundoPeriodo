#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include "bib.h"
#include <time.h>

struct noDuplamEncad  {
    int identificador;
    struct noDuplamEncad *prox;
    struct noDuplamEncad *ant;
};

struct listaCircular {
    int quant;
    struct noDuplamEncad* inicio;
};

Descritor *criarListaVazia() {
    Descritor *d;
    d = (Descritor*)malloc(sizeof(Descritor));
    if(d != NULL) {
        d->quant = 0;
        d->inicio = NULL;
    }
    else printf("Erro na memoria.\n");
}

Pessoa *criarNo() {
    Pessoa *p;
    p = (Pessoa*)malloc(sizeof(Pessoa));
    if (p != NULL) {
        p->ant = NULL;
        p->prox = NULL;
        return p;
    }
    else printf("Erro na memoria.\n");
}

void insereInicio(Descritor *d) {
    Pessoa *novo = criarNo();
    if (d->inicio == NULL) {
        d->inicio = novo;
        novo->prox = novo;
        novo->ant = novo;
    }
    else {
        novo->prox = d->inicio;
        novo->ant = d->inicio->ant;
        novo->ant->prox = novo;
        d->inicio = novo;
        d->inicio->ant = novo; 
    }
    d->quant++;
    novo->identificador = d->quant;
}

void praFrente(Descritor *d, int k, Pessoa **atual) {
    for(int i=0; i<k; i++) {
        *atual = (*atual)->prox;
    }
    remover(d, atual);
    (*atual) = (*atual)->ant;
}

void praTras(Descritor *d, int k, Pessoa **atual) {
    for(int i=0; i<k; i++) {
        *atual = (*atual)->ant;
    }
    remover(d, atual);
}

void remover(Descritor *d, Pessoa **atual) {
    Pessoa *aux;
    if(*atual == d->inicio) {
        d->inicio = (*atual)->prox;
        d->inicio->ant = (*atual)->ant;
        (*atual)->ant->prox = (*atual)->prox;
        aux = *atual;
        (*atual) = (*atual)->prox;   //para que atual possa ser utilizado no sorteio
        free(aux);
    }
    else {
        (*atual)->prox->ant = (*atual)->ant;
        (*atual)->ant->prox = (*atual)->prox;
        aux = (*atual);
        *atual = (*atual)->prox;    //para que atual possa ser utilizado no sorteio
        free(aux);
    }
    d->quant--;
}

void sorteio(Descritor *d) {
    setlocale(LC_ALL, "");
    
    srand(time(NULL));
    int num = rand () % (2 * (d->quant));
    num--;

    Pessoa *atual = d->inicio;

    while(d->quant > 1) {
        praFrente(d, num, &atual);
        if(d->quant == 1)  break;
        else continue;
        praTras(d, num, &atual);
    }

    printf("\nO líder escolhido foi a pessoa %d.\n\n", atual->identificador);
    free(atual);
    d->quant--;
}