#include <stdio.h>
#include <stdlib.h>
#include "bib.h"
#include <locale.h>

int main () {

    setlocale(LC_ALL, "");
    
    No *lal;
    lal = criarlistavazia();

    Aluno b;
    char c;

    int option;
    do {
    printf("Menu de opções: \n");
    printf("Digite 1 para cadastrar mais um aluno.\n");
    printf("Digite 2 para visualizar as notas de um aluno.\n");
    printf("Digite 3 para ver todos os alunos com nota total superior a 70.\n");
    printf("Digite 4 para remover um aluno.\n");
    printf("Digite 0 para sair do menu e encerrar.\n");
    scanf("%d", &option);
    printf("\n");

    switch (option)  {
        case 1: {
            printf("Digite o nome do aluno: ");
            while((c=getchar())!='\n'&&c!=EOF);
            scanf("%49[^\n]", b.nome);
            printf("Digite a nota prática do aluno: ");
            scanf("%d", &b.notaP);
            printf("Digite a nota teórica do aluno: ");
            scanf("%d", &b.notaT);
            lal = inserealuno(lal, b);

            printf("\n");
            break;
        }
        case 2: {
            char who [50];
            printf("Digite o nome do aluno do qual você deseja ver as notas. ");
            while((c=getchar())!='\n'&&c!=EOF);
            scanf("%49[^\n]", who);
            acha(lal, who);
            break;
        }
        case 3:
            superiores(lal);
            break;
        case 4: {
            char quem[50];
            scanf(" %49[^\n]", quem);
            remover(lal, quem);
            break;
        }
        case 0:
            break;
        default:
            break;
    }
    } while (option != 0);

    return 0;
}