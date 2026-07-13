#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "bib.h"

struct lista {
    char verbete[25];
    char classificacao[20];
    char significado[255];
    struct lista *prox;
};

struct no {
    char palavra[25];
    struct no *prox;
};

struct pilha {
    struct no *topo;
    int tam;
};

void criarListaVazia (Lista **l) {
    *l = NULL;
}

Lista *criarNo() {
    Lista *novo;
    novo = (Lista* )malloc(sizeof(Lista));
    if(novo != NULL) {
        novo->prox =NULL;
        return novo;
    }
}

void inserirPalavras(Lista **l) {
    printf("Tentando abrir arq.txt...\n"); // <-- Mensagem de teste
    FILE *fp = fopen("arq.txt", "r");
    if(fp == NULL)  {
        printf("Erro: O arquivo 'arq.txt' nao foi encontrado na pasta do projeto!\n");
        return;
    }
    
    printf("Lendo dados do arquivo...\n"); // <-- Mensagem de teste
    char v1[25], v2[25], v3[255];
    
    // O '\n' no final ajuda a consumir a quebra de linha do arquivo corretamente
    while(fscanf(fp, " %24[^;]; %19[^;]; %254[^\n]\n", v1, v2, v3) == 3) {
        Lista *novo = criarNo();
        if (novo != NULL) {
            strcpy(novo->verbete, v1);
            strcpy(novo->classificacao, v2);
            strcpy(novo->significado, v3);
            novo->prox = *l;
            *l = novo;
        }
    }
    fclose(fp);
    printf("Arquivo lido com sucesso e lista criada!\n"); // <-- Mensagem de teste
}

Lista *ordenar(Lista *l) {
    // Se a lista estiver vazia ou tiver apenas 1 elemento, já está ordenada
    if (l == NULL || l->prox == NULL) {
        return l;
    }

    Lista *atual_externo = l;

    // Percorre cada nó da lista
    while (atual_externo != NULL) {
        Lista *menor = atual_externo;
        Lista *atual_interno = atual_externo->prox;

        // Procura o menor elemento do resto da lista em diante
        while (atual_interno != NULL) {
            if (strcmp(menor->verbete, atual_interno->verbete) > 0) {
                menor = atual_interno;
            }
            atual_interno = atual_interno->prox; 
        }

        // Se o menor elemento não for o atual, trocamos os dados (strings)
        if (menor != atual_externo) {
            char *temp = atual_externo->verbete;
            strcpy(atual_externo->verbete, menor->verbete);
            strcpy(menor->verbete, temp);
        }

        // Avança para o próximo nó para repetir o processo
        atual_externo = atual_externo->prox;
    }

    return l;
}

void encontrar(Lista *l, char *nome) {
    setlocale(LC_ALL, "");
    Lista *atual = l;

    while(atual != NULL) {
        if ((strcmp(atual->verbete, nome)) == 0) {
            printf("\nClassificação do verbete: %s", atual->classificacao);
            printf("\nSignificado: %s", atual->significado);
            break;
        }
        atual = atual->prox;
    }
}

void iniciaPilha(Pilha **p) {
    *p = (Pilha*)malloc(sizeof(Pilha));
    (*p)->topo = NULL;
    (*p)->tam = 0;
}

void empilha(Pilha *p, char *palavra) {
    No* novoNo = (No*)malloc(sizeof(No));

    strcpy(novoNo->palavra, palavra);
    novoNo->prox = p->topo;
    p->topo = novoNo;
    p->tam++;
}

void leitura(Pilha *p) {
    FILE *fp = fopen("arq2.txt", "r");
    if(fp==NULL)  {
        printf("Erro ao abrir o arquivo.");
        return;
    }
    char word[25];
    while(fscanf(fp, "%24s", word) == 1) {
        empilha(p, word);
    }
    fclose(fp);
}

void desempilha(Pilha *p, Lista *l) {
    No *atual = p->topo;

    if (atual == NULL) {
        printf("\nA pilha esta vazia!\n");
        return;
    }

    // Enquanto houver elementos na pilha
    while (atual != NULL) {
        Lista *atual2 = l;
        int achou = 0;

        // Procura no dicionario (Lista)
        while(atual2 != NULL) {
            if(strcmp(atual2->verbete, atual->palavra) == 0) {
                printf("\nVerbete: %s", atual2->verbete);
                printf("\nClassificacao: %s", atual2->classificacao);
                printf("\nSignificado: %s\n", atual2->significado);
                achou = 1;
                break;
            }
            atual2 = atual2->prox; // Esse estava certo, mas previne se a lista sumir
        }

        No *temp = atual;
        atual = atual->prox; // Avança para o próximo da pilha
        free(temp);          // Libera o que acabou de ser lido
    }

    // Reseta a pilha para vazia
    p->topo = NULL;
    p->tam = 0;
    printf("\nPilha desempilhada por completo.\n");
}

void libera(Lista *l) {
    Lista *atual = l;
    while (atual != NULL) {
        Lista *temp = atual;
        atual = atual->prox;
        free(temp);
    }
}