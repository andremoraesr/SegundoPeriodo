#include <stdio.h>
#include <locale.h>
#include "media.h"

int main() {

    setlocale(LC_ALL, "");

    float num1, num2, num3;
 
    printf("Digite o primeiro número: ");
    scanf("%f", &num1);

    printf("Digite o segundo número: ");
    scanf("%f", &num2);

    printf("Digite o terceiro número: ");
    scanf("%f", &num3);
 
    media(num1, num2, num3);
    
    return 0;
}