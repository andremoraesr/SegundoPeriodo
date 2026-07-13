#ifndef BIB_H
#define BIB_H

typedef struct no No;
typedef struct pilha Pilha;
typedef struct lista Lista;

void criarListaVazia (Lista **l);
Lista *criarNo();
void inserirPalavras(Lista **l);
Lista *ordenar(Lista *l);
void encontrar(Lista *l, char *nome);
void iniciaPilha(Pilha **p);
void empilha(Pilha *p, char *palavra);
void leitura(Pilha *p);
void desempilha(Pilha *p, Lista *l);
void libera(Lista *l);

#endif