#define MAX 100 // Tamanho máximo da lista 

typedef struct { 
    int elementos[MAX]; // Vetor estático 
    int tamanho; // Número atual de elementos na lista 
} Lista; 

// Inicia a lista 
void iniciar(Lista *l) { 
    l->tamanho = 0; 
}

void inserir(Lista *l, int x)  {
    if(l->tamanho<MAX) {
        l->elementos[l->tamanho] = x;
        l->tamanho++;
    }
    else {
        printf("Memoria insuficiente.\n");
    }
}

void exibir(Lista l)  {
    for(int i=0; i<l.tamanho; i++)  {
        printf("%d ", l.elementos[i]);
    }
}

int main() { 
    Lista lista; 
    iniciar(&lista); 
    inserir(&lista, 10); 
    inserir(&lista, 20); 
    inserir(&lista, 30); 
    exibir(lista); // Saída: 10 20 30 
    return 0; 
}