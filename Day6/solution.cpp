//https://adventofcode.com/2020/day/6
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
    string tmpString = "";
    int length;

    while (getline(data, value)){
        length = tmpString.length();
        tmpString = tmpString + value;

        if(length == tmpString.length()){
            input.push_back(tmpString);
            tmpString = "";
        }  
    }
    data.close();
    return;  
}


void solutionPart1(vector <string> input){
    int counter = 0;
    vector <string> checksum;
    string tmp;

    for(string element: input){
        for(int i = 0; i < element.length(); i++){
            tmp = element.substr(i,1);
            if(count(checksum.begin(),checksum.end(), tmp) == 0){
                checksum.push_back(tmp);
            }
        }
        counter = counter + checksum.size();
        checksum.erase(checksum.begin(),checksum.end());
    }
    cout << counter << "\n";
}

void solutionPart2(){
    vector <vector <string>> input;
    ifstream data("input.txt");
    string value;
    vector <string> tmp;
    vector <string> checksum;
    vector <string> letters;
    string letter;
    string person;

    while (getline(data, value)){

        if(!value.size()){
            input.push_back(tmp);
            tmp.erase(tmp.begin(),tmp.end());
        }else{

            tmp.push_back(value);
        }


    }
    data.close();

    int counter = 0;

    for(vector <string> gruppe: input){
        for(string person: gruppe){
            for(int i = 0; i < person.size(); i++){
                letter = person.substr(i,1);
                //alle Buchstaben werden hinzugefügt
                letters.push_back(letter);
                //alle Buchstaben welche in der Gruppe vorkommen werden einmal hinzugefügt
                if(count(checksum.begin(),checksum.end(), letter) == 0){
                    checksum.push_back(letter);
                }
            }           
        }
        //überprüfe ob ein Buchstabe (aus der Menge welche vorkommen) genau so oft vorkommt wie es Personen in der Gruppe gibt
        for(string letterToCheck: checksum){
            if(count(letters.begin(),letters.end(),letterToCheck) == gruppe.size()){
                counter++;
            }
        }
        checksum.erase(checksum.begin(),checksum.end());
        letters.erase(letters.begin(),letters.end());
    }
    cout << counter << "\n";
}

int main(){
    vector <string> input;

    //inputToVektor(input);
    //solutionPart1(input);
    solutionPart2();

    return 0;
}