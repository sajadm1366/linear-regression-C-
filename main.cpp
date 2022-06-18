#include <iostream>
#include "regressor.h"
#include "utils.h"
#include <fstream>
#include <string>

using namespace std;



void train()
{
  Data data;
    string path = "data_regression.txt"; // path of the data
    load_data(data, path, "train");

    // define regressor
    Regressor reg;

    // train model
    reg.fit(data);

    // save the parameters
    ofstream myfile("model_regression.txt");
    myfile << reg.getWeight() << "\t" << reg.getBias();
    myfile.close();  
}

void eval()
{
    Data data;
    string path = "eval_data_regression.txt"; // path of the data for prediction
    load_data(data, path, "eval");

    // define regressor
    Regressor reg;

    // load the parameters
    string line;
    int pos;
    string x;
    ifstream myfile("model_regression.txt");
    getline(myfile, line);
    pos = line.find("\t");
    x = line.substr(0, pos);
    reg.setWeight(stof(x));
    x = line.substr(0, pos+1);
    reg.setBias(stof(x));
    myfile.close(); 


   // predict and save the results into  a file
   ofstream outfile("predcit_regression.txt");
   float predict;
   for (size_t i = 0; i < data.x.size(); i++)
   {
    predict = reg.predict(data.x[i]);
    outfile << predict << endl;
   }
    outfile.close();  

}

int main(int argc, char** argv)
{

string mode;
mode = argv[1];


if (mode == "train")  
{
 train();     // train the model
}else if (mode == "eval")
{
 eval(); // prediction
}

return 0;
}