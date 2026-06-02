#include <stdio.h>
#include <stdlib.h>
#include "bib.h"

struct no {
  int item;
  struct no* prox;
};

No* criaListaVazia(){
    return NULL;
}

// Função para inserir um elemento na lista
No* insereInicio(No *l, int elem){
    No* novo;
    novo = (No*) malloc (sizeof(No)); 
    if (novo == NULL) return novo;

    novo->item= elem;
    novo->prox = l;
    return novo;
}

int ehvazia(No *l)   {
    
    if(l==NULL) 
      return 1;
      else return 0;
}

No* removerElemento(No *l, int elem){
    No* atual, *ant;
    int achou = 0;
    if (l == NULL) return l;
    else {
        ant = NULL;
        atual = l;
        while (atual != NULL){
            if (atual->item == elem){ // elem. encontrado
            achou = 1; break;
            }
            else { // continua a busca
                ant = atual; // marcando o anterior e
                atual = atual->prox; // avançando p/ o próximo
                } 
        }
        if (achou == 1){
            if (atual == l) // é o primeiro
              l = l->prox;
              else // não é o primeiro
                  ant->prox = atual->prox;
                  free(atual); // libera memória
        }
          else printf("Elemento nao encontrado!\n");
            return l;
        }
}
