#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "bib.h"


    Lista *criarlista(int tam)  {

        Lista *l;
        l=(Lista*) malloc(sizeof(Lista));
        if(l!=NULL)  {
            l->dados = (Produto*) malloc(tam*sizeof(Produto));
            l->quant = 0;
            return l;
        }
        else
            return NULL;

}

    void insereprod(Lista *l, Produto p, int *tam)  {

        if(l->quant < *tam)  {
            l->dados[l->quant]=p;
            l->quant++;
        }
        else    {
            int newcap = (*tam)*2;
            Produto *temp = (Produto*) realloc(l->dados, newcap*sizeof(Produto));
                if(temp==NULL)
                    printf("Sem memoria!");
                else   {
                    l->dados = temp;
                    l->dados[l->quant]=p;
                    l->quant++;
                    *tam = newcap;
                }
        }
    }

     void cheaper(Lista *l)  {

        setlocale(LC_ALL, "");

        float menor;
        if (l->dados[0].valor <= l->dados[1].valor)  {
             menor = l->dados[0].valor;
        }
            else
                menor = l->dados[1].valor;


        for(int c=2; c<l->quant; c++)  {
            if(menor > l->dados[c].valor)  {
                menor = l->dados[c].valor;
            }
        }
            
        int i=0;
        while(menor!=l->dados[i].valor)  {
            i++;
        }

        printf("O produto de menor preço é: %s, por %f reais.\n", l->dados[i].nomeProd, l->dados[i].valor);
    }
    
    void venda(Lista *l, int a, int b)  {

        setlocale(LC_ALL, "");

        if(l->dados[b-1].qtdeEstoque >= a)  {
            FILE *fp2 = fopen("arq.txt", "r+");
                if (fp2==NULL)  {
                    printf("Erro ao abrir o arquivo.");
                    exit (1);
                }
            l->dados[b-1].qtdeEstoque = l->dados[b-1].qtdeEstoque - a;
            printf("Você acabou de comprar %d unidades de %s. Obrigado!", a, l->dados[b-1].nomeProd);
            fclose(fp2);
        }
            else 
            printf("O estoque deste produto não é suficiente para a quantidade desejada. \n");
        
        FILE *fp3 = fopen("arq.txt", "w");
        if (fp3==NULL)  {
            printf("Erro ao abrir o arquivo.");
            exit (1);
       }

       for(int j=0; j<l->quant; j++)  {
            fprintf(fp3, "%03d; %s; %.2f; %d\n", 
                l->dados[j].codProd, 
                l->dados[j].nomeProd, 
                l->dados[j].valor, 
                l->dados[j].qtdeEstoque);
       }
       fclose(fp3);
    }

