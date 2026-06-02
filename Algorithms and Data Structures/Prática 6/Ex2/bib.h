#ifndef BIB_H
#define BIB_H

typedef struct no No;

No* criaListaVazia();
No* insereInicio(No *l, int elem);
int ehvazia(No *l);
No* removerElemento(No *l, int elem);

#endif