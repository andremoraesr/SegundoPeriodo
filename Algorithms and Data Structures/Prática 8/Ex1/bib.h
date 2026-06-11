#ifndef BIB_H
#define BIB_H

typedef struct no No;
typedef struct desc Descritor;

Descritor *criarlista();
No *criarNo();
void insereInicio(Descritor *d, int x);
void insereFinal(Descritor *d, int x);
void removeInicio(Descritor *d);
void removeFinal(Descritor *d);
void removeElem(Descritor *d, int x);
void exibe(Descritor *d);

#endif