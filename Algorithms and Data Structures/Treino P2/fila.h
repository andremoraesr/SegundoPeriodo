#ifndef FILA_H
#define FILA_H

typedef struct software No;
typedef struct fila Fila;

Fila *iniciaFila();
void insere(Fila *f, char *nome, char *titulo, char *linguagem, int ano);
void remove(Fila *f);

#endif