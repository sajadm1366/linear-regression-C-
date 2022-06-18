#ifndef UTILS_H
#define UTILS_H

#include <vector>
#include <string>

struct Data
{
    std::vector<float> x;
    std::vector<float> y;
};



// 
void load_data(::Data &data, std::string path, std:: string mode);


#endif