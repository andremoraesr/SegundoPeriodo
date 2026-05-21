#include <stdio.h>
#include <stdlib.h>

int main() {
    int *vetor = (int *)malloc(3 * sizeof(int));   // Aloca espaço para 3 inteiros

    for (int i = 0; i < 3; i++) {    // Solicita 3 números ao usuário
        printf("Digite um número: ");
        scanf("%d", &vetor[i]);
    }
    
    vetor = (int *)realloc(vetor, 4 * sizeof(int));     // Expande o vetor para armazenar mais um número
       
    printf("Digite mais um número: ");    // Solicita o quarto número
    scanf("%d", &vetor[3]);

    printf("\nNúmeros armazenados: ");    // Exibe os números armazenados
    for (int i = 0; i < 4; i++) {
        printf("%d ", vetor[i]);
    }

    vetor = (int *) realloc (vetor, 2 * sizeof(int));
    printf("\nA metade da sequencia armazenada: ");
    for(int i=0; i<2; i++) {
        printf("%d ", vetor[i]);
    }

    free(vetor);     // Libera a memória alocada
    return 0;
}