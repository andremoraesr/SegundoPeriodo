#include <stdio.h>
#include <stdlib.h>
#include "bib.h"
#include <locale.h>

int main () {

    Descritor *lista;
    lista = criarlista();

    int option;

    do {
        scanf("%d", &option);
        switch (option) {
            case 1: {
                int y;
                scanf("%d", &y);
                insereInicio(lista, y);
                break;
            }
            case 2: {
                int z;
                scanf("%d", &z);
                insereFinal(lista, z);
                break;
            }
            case 3:
                removeInicio(lista);
                break;
            case 4:
                removeFinal(lista);
                break;
            case 5: {
                int a;
                scanf("%d", &a);
                removeElem(lista, a);
                break;
            }
            case 6:
                exibe(lista);
                break;
            default:
                break;
        }
    } while (option != 0);

    return 0;
}