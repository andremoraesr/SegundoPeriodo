#ifndef BIB_H
#define BIB_H

typedef struct no No;

void criaListaVazia(No **l);
No* criarNo();
void inserir(No **l);
void busca(No *l, char *s);
void tirarepet(No **l);
void tiraUma(No **l, char *s);
void tiraprimos(No *l, No **lp);
int quantasVezes(No *l);
void liberar(No *l);
void exibir(No *l);

#endif