#include <stdio.h>
#include "bib.h"
#include <stdlib.h>

int main() {
    ListaDinamica lista;
    iniciar(&lista, 2);
    
    inserir(&lista, 10);
    inserir(&lista, 20);
    inserir(&lista, 30);  // Aqui ocorre a realocação

    exibir(&lista);  // Saída: 10 20 30
    liberar(&lista);
    return 0;
}