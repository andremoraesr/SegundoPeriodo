#include <stdio.h>
#include <stdlib.h>
#include "bib.h"
#include <locale.h>
#include <string.h>

struct no {
   char palavra[30];
   struct no *prox;
};

void criaListaVazia(No **l){
   *l = NULL;
}

No* criarNo() {
    No* novoNo = (No*)malloc(sizeof(No));
    if(novoNo!=NULL) return novoNo;
}

void inserir(No **l) {

    FILE *fp = fopen("arq.txt", "r");
    if(fp==NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }
    char s[30];
    while(fscanf(fp, "%s", s) == 1) {
        No *novo = criarNo();
        strcpy(novo->palavra, s);
        novo->prox = *l;
        *l=novo;
    }
    fclose(fp);
}

void busca(No *l, char *s) {

    int achei = 0;
    No *atual;
    atual = l;

    if(l != NULL) {
        while(atual!=NULL) {
            if(strcmp(atual->palavra, s)==0)  {
                achei = 1; 
                break;
            }
            else {
                atual = atual->prox;
            }
        }
        if (achei == 1) {
            printf("Essa palavra existe. \n\n");
        }
        else
            printf("A palavra nao foi encontrada. \n\n");
    }
}

void tirarepet(No **l) {

    No *atual = *l;

    while (atual != NULL ){
        No **pp = &(atual->prox);
        while(*pp != NULL) {
            if (strcmp((*pp)->palavra, atual->palavra) == 0) {
                No *duplic = *pp;
                *pp = (*pp)->prox;
                free(duplic);
            }
            else {
                pp = &(*pp)->prox;
            }
        }
        atual = atual->prox;
    }
}

void tiraUma(No **l, char *s) {
    
    No *atual = *l;
    No *anterior = NULL;
    int sucess = 0;
    while(atual != NULL){
        if (strcmp(s, atual->palavra) == 0) {
            if(anterior == NULL) {
                *l = atual->prox;
            }
            else {
                anterior->prox = atual->prox;
            }
            free(atual);
            sucess=1;
            break;
        }
        else {
            anterior = atual;
            atual = atual->prox;
        }
}
    if(sucess==1) {
        printf("A palavra foi removida.\n\n");
    }
    else {
        printf("A palavra nao pode ser removida.\n\n");
    }
}

void tiraprimos(No *l, No **lp) {

    No *atual = l;
    if (l == NULL) 
        return;
    while(atual != NULL) {
        int tam = strlen(atual->palavra);
        int cont = 0;
        for (int i=1; i<=tam; i++) {
            if((tam%i)==0) {
                cont++;
            }
        }
        if(cont<=2) {
            No *novo;
            novo = criarNo();
            strcpy(novo->palavra, atual->palavra);
            novo->prox = *lp;
            *lp = novo;
        }
        atual = atual->prox;
    }
}

int quantasVezes(No *l) {

    if(l == NULL) {
        return 0;
    }
    return 1 + quantasVezes(l->prox);
}

void liberar(No *l) {

    No *atual = l;
    while (atual!=NULL) {
        No *temp = atual;
        atual = atual->prox;
        free(temp);
    }
}

void exibir(No *l) {

    No *atual = l;
    while(atual != NULL) {
        printf("%s  ", atual->palavra);
        atual=atual->prox;
    }
    printf("\n");
}