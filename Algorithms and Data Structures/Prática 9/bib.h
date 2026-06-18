#ifndef BIB_H
#define BIB_H

typedef struct nave Nave;
typedef struct lc Listac;

Listac *criarlistavazia();
Nave *criarnave();
void insere(Listac *l, int x, int y);
void ciclo (Listac *l, int a, int *ciclos);
void exibir(Listac *l);
void libera(Listac *l);

#endif