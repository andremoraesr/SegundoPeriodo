#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include "bib.h"

int main () {
    
    setlocale(LC_ALL, "");

    Descritor *l = criarListaVazia();
    int option, id = 1;

    do {
        printf("1 - Inserir uma nova pessoa no sorteio.\n");
        printf("2 - Realizar o sorteio.\n");
        printf("0 - Sair.\n");
        scanf("%d", &option);

        switch (option) {
            case 1: 
                insereInicio(l);
                printf("\nVocê inseriu a pessoa %d na lista.\n", id);
                id++;
                break;
            case 2:
                sorteio(l);
                break;
            default:
                break;
        }
    } while (option != 0);


    return 0;
}