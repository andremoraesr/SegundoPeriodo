#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "bib.h"

int main () {

    setlocale(LC_ALL, "");

    int option;
    Listac *lp = criarlistavazia();

    do {
        printf("1 - Inserir nova nave na lista.\n");
        printf("2 - Exibir as naves cadastradas.\n");
        printf("3 - Realizar ciclo de abastecimento.\n");
        printf("0 - Sair.\n");
        printf("\n");
        scanf("%d", &option);
        switch (option) {
            case 1: {
                int j, k;
                printf("\nCapacidade do tanque da nova nave: ");
                scanf("%d", &j);
                printf("Nível inicial do combustível da nave: ");
                scanf("%d", &k);
                insere(lp, j, k);
                break;
            } 
            case 2:
                exibir(lp);
                break;
            case 3: {
                int a, ciclos = 0;
                printf("\nLitros inseridos a cada ciclo: ");
                scanf("%d", &a);
                ciclo(lp, a, &ciclos);
                printf("\nCiclos necessários para completar todos os abastecimentos: %d.\n", ciclos);
                break;
            }
            default:
                break;
        }
    } while(option != 0);

    libera(lp);

    return 0;
}