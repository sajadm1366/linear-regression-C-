#include <iostream>
#include "utils.h"
#include <fstream>
#include <string>


using namespace std;

void load_data(Data &data, std::string path, string mode){
    /*
    load the data ans store into vectors
    inputs:
        data: an empty struct x, y
        path: path of the data in .txt format
    outputs:
        data: fill up data x, y
    */

    std::string line;
    int pos;
    if (mode == "train")
    {
       std::string x, y;
    

    std::ifstream myfile (path);
    while (getline(myfile, line) )
    {
      pos = line.find("\t");
      x = line.substr(0, pos);
      y = line.substr(pos+1);
      data.x.push_back(stof(x));
      data.y.push_back(stof(y));
    }
    myfile.close();  
    } else if (mode == "eval")
    {
    std::string x;
    std::ifstream myfile (path);
    while (getline(myfile, line) )
    {
      pos = line.find("\t");
      x = line.substr(0, pos);
      data.x.push_back(stof(x));
    }
    myfile.close();  
    }
    
    
    
}