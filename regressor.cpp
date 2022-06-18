#include <iostream>
#include <random>
#include <chrono>
#include "regressor.h"
#include "utils.h"

unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
std::default_random_engine generator (seed);
std::normal_distribution<double> distribution (0.0, 1.0);


void grad(const Data data, const float weights, const float bias,  float grad_val[])
{
    grad_val[0] = 0;
    grad_val[1] = 0;

    for (size_t i = 0; i < data.x.size(); i++)
    {
        grad_val[0] += (-data.x[i] * 2 * (data.y[i] - weights * data.x[i] - bias));
        grad_val[1] += (- 2 * (data.y[i] - weights * data.x[i] - bias));
    }
    grad_val[0]  = grad_val[0] / data.x.size();
    grad_val[1]  = grad_val[1] / data.x.size();
    
}

void update(float *weight, float *bias, float grad_val[], float lr)
{
    *weight -= lr * grad_val[0];
    *bias -= lr * grad_val[1];
}



Regressor::Regressor()
{
    weights = distribution(generator);
    bias = distribution(generator);
    lr = 0.01;
}

float Regressor::getWeight()
{
   return weights;
}

float Regressor::getBias()
{
   return bias;
}

void Regressor::setWeight(float weights)
{
   this->weights = weights;
}

void Regressor::setBias(float bias)
{
   this->bias = bias;
}

void Regressor::fit(const Data data)
{
    int iterations = 2000;
    float grad_val[2] = {0, 0}; // initlize grad values

    for (size_t i = 0; i < iterations; i++)
    {
        ::grad(data, weights, bias, grad_val); // compute grads

        ::update(&weights, &bias, grad_val, lr);

    }
    
}


float Regressor::predict(float x_new){
        return weights*x_new + bias;
}


