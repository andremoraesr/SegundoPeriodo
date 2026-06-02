#include <stdio.h>
#include <stdlib.h>
#include "bib.h"

int main(){
    
    No *lnum; // lista de números com encadeamento de nós 
    int val; 
    lnum = criaListaVazia();  
    for(int i=0;i<5;i++){  //  inserir 10 elementos    
        scanf("%d",&val);
        lnum = insereInicio(lnum, val);
    }

    ehvazia(lnum);

    printf("Qual elemento vc quer remover? ");
    int rem;
    scanf("%d", &rem);
    removerElemento(lnum, rem);

    



    return 0;
}