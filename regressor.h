#ifndef REGRESSOR_H
#define REGRESSOR_H
#include "utils.h"

class Regressor
{
    /*
    linear regession class
    */
private:
    float weights;
    float bias;
    float lr;

public:
    Regressor();
    void fit(const Data data);
    float predict(float x_new);
    float getWeight();
    float getBias();
};


#endif