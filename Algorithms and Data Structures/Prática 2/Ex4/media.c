#include <stdio.h>
#include <locale.h>
#include "media.h"

float media(float x, float y, float z)  {

    float a = z + (x+y)/2;

    if(a>10)
        a=10;
    
    return a;
}