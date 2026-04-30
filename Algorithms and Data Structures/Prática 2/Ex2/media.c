#include <stdio.h>
#include "media.h"
#include <locale.h>

    void media(float x, float y, float z)  {

        setlocale(LC_ALL, "");

        float m=(x+y+z)/3;
        printf("A média desses números é: %f", m);
    }