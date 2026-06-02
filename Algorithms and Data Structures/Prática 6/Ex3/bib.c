#include <stdio.h>
#include <stdlib.h>
#include "bib.h"
#include <string.h>
#include <locale.h>

No* criarlistavazia() {
    return NULL;
}

No *inserealuno(No *l, Aluno a) {

    No* novo;
    novo = (No*) malloc(sizeof (No));
    if(novo == NULL) return novo;

    novo->dados = a;
    novo->prox = l;
    return novo;
}

void acha(No *l, char *qual){

    setlocale(LC_ALL, "");

    No *atual;
    int achei=0;
    atual=l;

    if(l!=NULL){
        while (atual !=NULL) {
            if(strcmp(atual->dados.nome, qual)==0) {
                achei = 1; break;
            }
            else
                atual=atual->prox;
        }
    }
    if(achei == 1) {
        int soma = atual->dados.notaP + atual->dados.notaT;
        printf("%d", soma);
    }
}

void superiores(No *l){

    No *atual;
    atual = l;
    int soma = atual->dados.notaP + atual->dados.notaT;
    
    while (atual != NULL) {
        if(soma > 70) {
            printf("%s", atual->dados.nome);
            printf("\n");
            atual = atual->prox;
        }
        else 
            atual = atual->prox;
    }
}

No *remover(No *l, char *qual) {

    setlocale(LC_ALL, "");

    No *atual, *ant;
    int achei=0;
    if(l==NULL) return l;
    else {
        ant=NULL;
        atual=l;
        while (atual !=NULL) {
            if(strcmp(atual->dados.nome, qual)==0) {
                achei = 1; break;
            }
            else
                ant=atual;
                atual=atual->prox;
        }
    }
    if (achei==1) {
        if(atual == l) {
            l=l->prox;
        }
        else {
            ant->prox=atual->prox;
        }
    free(atual);
    }
    return l;
}

