//https://adventofcode.com/2020/day/1
//Feniel

#include <fstream>
#include <vector>
#include <string>

using namespace std;

void inputToVektor(vector <int> &input){
    ifstream data("input.txt");
    string value;

    while (getline(data, value))
    {
        int tmp = 0;
        try{
            tmp << stoi( value ); 
        }
        catch{
            cout << "Bad input" << "\n";
        }
        input.push_back(tmp);
    }
    data.close();
    return;  
}

int main(){
    vector <int> input;
    int output = 0;

    inputToVektor(input);

    //printf (output);
    //return 0;
    return vector[2];
}