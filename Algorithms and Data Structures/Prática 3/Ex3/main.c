#include <stdio.h>

int main ()   {

    float v[10];

    for(int i=0; i<10; i++)   {
        printf("Endereco: %p\n", v+i);
    }

    return 0;
}