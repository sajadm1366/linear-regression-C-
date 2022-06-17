#ifndef UTILS_H
#define UTILS_H

#include <vector>

struct Data
{
    std::vector<float> x;
    std::vector<float> y;
};



// compute dot produst of two arrays
float dot(const float x[], const float y[], int size);


#endif