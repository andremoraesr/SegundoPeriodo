#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "livros.h"
#include <string.h>


lista *criarlista(int tam)  {

    lista *l;
    l = (lista*) malloc (sizeof(lista));
    if(l!=NULL)  {
        l->dados = (livro*) malloc (tam*sizeof(livro));
        l->quant = 0;
        l->cap = tam;
        return l;
    }
    else return NULL;
}

void insere(lista *l, livro v)  {

    if(l->quant<l->cap)  {
        l->dados[l->quant]=v;
        l->quant++;
    }
    else  {
        int newcap=l->cap*2;
        livro *temp=(livro*) realloc(l->dados, newcap*sizeof(livro));
            if(temp==NULL)  {
                printf("Sem memoria.");
            }
            else {
                l->dados=temp;
                l->cap=newcap;
                l->dados[l->quant]=v;
                l->quant++;
            }

    }
}

void excluir(lista *l, char *tit)   {

    int achei=0;
    for (int i=0; i<l->quant; i++)  {
        if(strcmp(l->dados[i].titulo, tit)==0)  {
            l->dados[i]=l->dados[l->quant-1];
            l->quant--;
            printf("O livro foi removido com sucesso.\n\n");
            achei=1;
            break;
        }
    }
    if (achei == 0)
    printf("O livro nao foi encontrado.");
}

void imprime (lista *l)  {

    setlocale(LC_ALL, "");
    
    printf("Os livros cadastrados são: \n\n");

    for(int i=0; i<l->quant; i++)  {
        printf("Título: %s.\n", l->dados[i].titulo);
        printf("Autor: %s.\n", l->dados[i].autor);
        printf("Ano: %d.\n", l->dados[i].ano);
        printf("Preço: R$%.2f.\n\n", l->dados[i].preco);
    }
}

