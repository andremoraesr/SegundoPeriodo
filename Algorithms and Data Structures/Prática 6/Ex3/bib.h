#ifndef BIB_H
#define BIB_H

struct aluno {
    char nome[50];
    int notaP, notaT;
};
typedef struct aluno Aluno;

struct no {
    Aluno dados;
    struct no *prox;
};
typedef struct no No;

No *criarlistavazia();
No *inserealuno(No *l, Aluno a);
void acha(No *l, char *qual);
void superiores(No *l);
No *remover(No *l, char *qual);

#endif