//https://adventofcode.com/2020/day/3
//Feniel

#include <fstream>
#include <vector>
#include <string>
#include <iostream>

#include <algorithm>

using namespace std;

void inputToVektor(vector<string> &input){
    ifstream data("input.txt");
    string value;

    while (getline(data, value)){
        input.push_back(value);
    }
    data.close();
    return;  
}

void solutionPart1(vector <string> input){
    string tmp;
    int counter = 0;
    int line = 3;

    for (int columns = 1; columns < input.size(); columns++){
    //for (int columns = 1; columns < 3; columns++){
        line = line % 31;
        tmp = input[columns][line];
        if(tmp.compare("#") == 0){
            counter++;
        }
        line = line + 3;
    }
    cout << counter << "\n";
}

void solutionPart2(vector <string> input){
    string tmp;
    long output = 1;
    int counter = 0;
    vector<int> right {1,3,5,7,1};
    vector<int> down {1,1,1,1,2};

    for (int i=0; i < 5; i++){
        int line = right[i];

        for (int columns = down[i]; columns < input.size(); columns=columns+down[i]){
            line = line % 31;
            tmp = input[columns][line];
            if(tmp.compare("#") == 0){
                counter++;
            }
            line = line + right[i];
        }       
        output = output * counter;
        counter = 0;
    }
    cout << output << "\n";
}

int main(){
    vector<string> input;

    inputToVektor(input);
    solutionPart1(input);
    solutionPart2(input);

    return 0;
}