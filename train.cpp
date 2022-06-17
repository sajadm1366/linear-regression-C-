#include <iostream>
#include "regressor.h"
#include "utils.h"
#include <fstream>
#include <string>

using namespace std;

void load_data(Data &data, string path){
    /*
    load the data ans store into vectors
    inputs:
        data: an empty struct x, y
        path: path of the data in .txt format
    outputs:
        data: fill up data x, y
    */

    string line;
    string x, y;
    int pos;

    ifstream myfile (path);
    while (getline(myfile, line) )
    {
      pos = line.find("\t");
      x = line.substr(0, pos);
      y = line.substr(pos+1);
      data.x.push_back(stof(x));
      data.y.push_back(stof(y));
    }
    myfile.close();  
}


int main()
{

Data data;
string path = "data_regression.txt"; // path of the data
load_data(data, path);

// define regressor
Regressor reg;

// train model
reg.fit(data);


// save the parameters
ofstream myfile ("model_regression.txt");
myfile << reg.getWeight() << "\t" << reg.getBias();
myfile.close();  

return 0;
}