//https://adventofcode.com/2020/day/2
//Feniel


#include <fstream>
#include <vector>
#include <string>
#include <iostream>

#include <algorithm>

using namespace std;

void inputToVektor(vector <string> &input){
    ifstream data("input.txt");
    string value;

    while (getline(data, value)){
        int tmp = 0;

        input.push_back(value);
    }
    data.close();
    return;  
}

void solutionPart1(vector <string> input){
    int counter = 0;

    for (int i = 0; i < input.size(); i++){

        string quantitiy = input[i].substr(0,input[i].find(" "));
        string strMin = quantitiy.substr(0,quantitiy.find("-"));
        int min = stoi( strMin );
        string strMax = quantitiy.substr(quantitiy.find("-")+1,quantitiy.size());
        int max = stoi( strMax );

        input[i].erase(0,quantitiy.size());

        string tmp = input[i];
        char checksum = tmp[1];

        input[i].erase(0,input[i].find(":")+2);

        int number = count(input[i].begin(),input[i].end(),checksum);

        if(number <= max & number >= min){
            counter++;
        }
    }
    cout << counter << "\n";
}

void solutionPart2(vector <string> input){
    int counter = 0;

    for (int i = 0; i < input.size(); i++){

        string quantitiy = input[i].substr(0,input[i].find(" "));
        string strPosition1 = quantitiy.substr(0,quantitiy.find("-"));
        int position1 = stoi( strPosition1 );
        string strPosition2 = quantitiy.substr(quantitiy.find("-")+1,quantitiy.size());
        int position2 = stoi( strPosition2 );

        input[i].erase(0,quantitiy.size());

        string tmp = input[i];
        char checksum = tmp[1];

        input[i].erase(0,input[i].find(":")+2);

        tmp = input[i].substr(position1-1,position2 - position1 + 1);
        char charPosition1 = tmp[0];
        char charPosition2 = tmp[tmp.size()-1];
        
        if(charPosition1 == checksum){
            if(charPosition2 != checksum){
                counter++;
            }
        }else{
            if(charPosition2 == checksum){
                counter++;
            }
        }
    }
    cout << counter << "\n";
}

int main(){
    vector <string> input;

    inputToVektor(input);
    solutionPart1(input);
    solutionPart2(input);

    return 0;
}