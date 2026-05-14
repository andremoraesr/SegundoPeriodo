#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "bib.h"


    Lista *criarlista(int tam)  {

        Lista *l;
        l=(Lista*) malloc(sizeof(Lista));
        if(l=!NULL)  {
            l->dados = (Produto*) malloc(tam*sizeof(Produto));
            l->quant = 0;
        }
        else
            return NULL;

}

    void insereprod(Lista *l, Produto p, int tam)  {

        if(l->quant < tam)  {
            l->dados[l->quant]=p;
            l->quant++;
        }
        else    {
            int newcap=2*tam;
            Produto *temp = (Produto*) realloc(l->dados, newcap*sizeof(Produto));
                if(temp==NULL)
                    printf("Sem memoria!");
                else   {
                    l->dados[l->quant]=p;
                    l->quant++;
                }
        }
    }

     void cheaper(Lista *l, Produto p)  {

            setlocale(LC_ALL, "");

            int menor;
            for(int c=0; c<l->quant; c++)  {
                if()
            }
        }