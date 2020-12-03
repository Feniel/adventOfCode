//https://adventofcode.com/2020/day/1
//Feniel

#include <fstream>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

void inputToVektor(vector <int> &input){
    ifstream data("input.txt");
    string value;

    while (getline(data, value))
    {
        int tmp = 0;
        try{
            tmp = stoi( value ); 
        }
        catch(const exception &e){
            cout << "Bad input" << "\n";
        }
        input.push_back(tmp);
    }
    data.close();
    return;  
}

void solution(vector <int> &input){
    int tmp = 0;

    for (int i = 0; i < input.size(); i++){
        
        for (int g = i+1; g < input.size(); g++){
            
            if(input[i]+input[g] == 2020){
                tmp = input[i] * input[g];
                cout << tmp << "\n";
                return;
            } 
        }
    }
}

int main(){
    vector <int> input;

    inputToVektor(input);
    solution(input);

    return 0;
}