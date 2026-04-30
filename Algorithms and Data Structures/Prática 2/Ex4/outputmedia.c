#include <stdio.h>
#include <locale.h>
#include "outputmedia.h"
#include "media.h"

void outputmedia(float m) {

    setlocale(LC_ALL, "");
    
        printf("A média final do aluno é: %f", m);
}