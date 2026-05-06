#include <stdio.h>
#include "ordena.h"

int ordena(int vet[3])  {

    int troca;

    if(vet[2]<vet[1])  {
        troca=vet[2];
        vet[2]=vet[1];
        vet[1]=troca;
    }
    if (vet[2]<vet[0])  {
        troca=vet[2];
        vet[2]=vet[0];
        vet[0]=troca;
    }
    else if (vet[1]<vet[0])   {
        troca=vet[1];
        vet[1]=vet[0];
        vet[0]=troca;
    }
    
    for (int i=0; i<3; i++)  {
        printf("%d ", vet[i]);
    }

    if (vet[0]==vet[1] && vet[0]==vet[2])
        return 1;
        else 
            return 0;
}