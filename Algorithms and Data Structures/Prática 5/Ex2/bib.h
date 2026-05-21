#ifndef BIB_H
#define BIB_H

    typedef struct {
    int *elementos;  // Vetor dinâmico
    int tamanho;
    int capacidade;
} ListaDinamica;

void iniciar(ListaDinamica *l, int capacidade);

void inserir(ListaDinamica *l, int x);

void exibir(ListaDinamica *l);

void liberar(ListaDinamica *l);

#endif