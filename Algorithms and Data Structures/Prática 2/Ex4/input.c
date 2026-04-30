#include <stdio.h>
#include <locale.h>
#include "input.h"
#include "outputmedia.h"
#include "media.h"

void input()  {

    setlocale(LC_ALL, "");

    struct ALUNO {
        char nome[50];
        float media;
    };

    struct ALUNO alunos[20];

    for(int i=0; i<20; i++)  {
        float n1, n2, p;

        printf("Digite o nome do aluno %d: ", i+1);
        scanf("%49[^\n]", alunos[i].nome);
        
        printf("Digite as notas da primeira e segunda prova do aluno %d, além dos seus pontos de participação: ", i+1);
        scanf("%f %f %f", &n1, &n2, &p);
        setbuf(stdin, NULL);
        
        alunos[i].media=media(n1, n2, p);
        outputmedia(alunos[i].media);
        printf("\n");
    }

}