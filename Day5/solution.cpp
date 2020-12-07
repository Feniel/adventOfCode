//https://adventofcode.com/2020/day/2
//Feniel


#include <fstream>
#include <vector>
#include <string>
#include <iostream>

#include <algorithm>
#include <math.h>

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

void solutionPart1(vector <string> input, vector <int> &seatCodes){
    string lineString;
    int left;
    int right;
    int tmpInt = 0;
    string tmp;
    int maxOutput = 0;
    int seatCode;

    for (int i = 0; i < input.size(); i++){
        lineString = input[i];
        left = 0;
        right = 127;

        for(int j = 0; j < 7; j++){
            tmp = lineString.substr(j,1);
            if(tmp.compare("F") == 0){
                right = (right+left) / 2;
            }else{   
                left = ((right+left) / 2) + 1;
            }   
        }
        if(left == right){
            tmpInt = right;
            left = 0;
            right = 7;

            for(int h = 7; h < 10; h++){
                tmp = lineString.substr(h,1);

                if(tmp.compare("L") == 0){
                    right = (right+left) / 2;
                }else{   
                    left = ((right+left) / 2) + 1;
                }
            }
            seatCode = ((tmpInt * 8) + right);
            seatCodes.push_back(seatCode);
            if( seatCode > maxOutput ){
                maxOutput = seatCode;
            }
        }else{
            cout << "Equal Number Error" << "\n";
            cout << left << "\n"; 
            cout << right << "\n";  
        }
        left = 0;
        right = 127;
    }
    cout << maxOutput << "\n";
}

void solutionPart2(vector <string> input, vector <int> &seatCodes){
    int counter = 0;

    sort(seatCodes.begin(), seatCodes.end());

    //for(int seatCode: seatCodes){
    //    cout << seatCode << "\n";
    //}

    for (int i = 0; i < seatCodes.size() - 1; i++){
        if(seatCodes[i] + 1 != seatCodes[i+1]){
            cout << (seatCodes[i] + 1) << "\n";
        }
        
    }
}

int main(){
    vector <string> input;
    vector <int> seatCodes;

    inputToVektor(input);
    solutionPart1(input, seatCodes);
    solutionPart2(input, seatCodes);

    return 0;
}