#ifndef BIB_H
#define BIB_H

typedef struct noDuplamEncad Pessoa;
typedef struct listaCircular Descritor;

Descritor *criarListaVazia();
Pessoa *criarNo();
void insereInicio(Descritor *d);
void praFrente(Descritor *d, int k, Pessoa **atual);
void praTras(Descritor *d, int k, Pessoa **atual);
void remover(Descritor *d, Pessoa **atual);
void sorteio(Descritor *d);

#endif