#include <stdio.h>
#include <stdlib.h>
#include "fila.h"


int main() {

    Fila *f = iniciaFila();
    char titulo[25];
    char autor [50];
    int ano;
    char linguagem[15];

    for(int i=0; i<5; i++) {
        printf("\nDigite o nome do autor: ");
        scanf("%49[^\n]", autor);
        printf("\nDigite o titulo do software: ");
        scanf("%24[^\n]", titulo);
        printf("\nDigite a linguagem usada: ");
        scanf("%14[^\n]", linguagem);
        printf("\nDigite o ano de criacao: ");
        scanf("%d", &ano);
        insere(f, autor, titulo, linguagem, ano);
    }

    remove(f);

    return 0;
}