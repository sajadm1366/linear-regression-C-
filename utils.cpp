#include <iostream>
#include "utils.h"



float dot(const float x[], const float y[], int size)
{
    float dot_product=0;
    for (int i = 0; i < size; i++)
    {
        dot_product += x[i] * y[i];
    }
    return dot_product;
    
}