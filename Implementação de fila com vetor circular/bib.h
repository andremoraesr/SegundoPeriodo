#ifndef BIB_H
#define BIB_H

typedef struct fila Fila;

Fila *criarFila(int x);
void enfileira(Fila *f, double y);
double desenfileirar(Fila *f);
int quant(Fila *f);
void percorre(Fila *f);
void libera(Fila *f);
int empty(Fila *f);

#endif