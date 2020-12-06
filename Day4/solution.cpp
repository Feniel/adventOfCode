//https://adventofcode.com/2020/day/4
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
    vector<string> tmp;
    int counter = 0;
    int workSize;
    vector<string> keywords{"byr","iyr","eyr","hgt","hcl","ecl","pid"};
    int keywordCounter = 0;
    
    for (int lineCounter = 0; lineCounter < input.size(); lineCounter++){
        tmp.push_back(input[lineCounter]);
        if(input[lineCounter].empty()){
            workSize = tmp.size() - 1;           

            for (int i = 0; i < workSize; i++){

                for (int j = 0; j < keywords.size(); j++){
                    if(tmp[i].find(keywords[j]) != string::npos){
                        keywordCounter++;
                    }
                }
            }
            
            if(keywordCounter == 7){
                counter++;
            }

            keywordCounter = 0;
            tmp.clear();
        }
    }

    cout << counter << "\n";
}

void solutionPart2(vector <string> input){
    vector<string> tmp;
    int counter = 0;
    int workSize;
    vector<string> keywords{"byr","iyr","eyr","hgt","hcl","ecl","pid"};
    int keywordCounter = 0;
    string tmpString;
    string tmpNum;

    for (int lineCounter = 0; lineCounter < 4; lineCounter++){
        tmp.push_back(input[lineCounter]);
        if(input[lineCounter].empty()){
            workSize = tmp.size() - 1;           

            for (int i = 0; i < workSize; i++){

                for (int j = 0; j < keywords.size(); j++){
                    if(tmp[i].find(keywords[j]) != string::npos){
                        tmpString = tmp[i].substr( tmp[i].find(keywords[j]) , tmp[i].find(" ",tmp[i].find(keywords[j])) );

                        if (tmpString.find("byr") != string::npos){
                            tmpNum = tmpString.substr( tmpString.find(":") + 1 , tmpString.size() - tmpString.find(":") );
                            if(stoi (tmpNum) >= 1920 & stoi (tmpNum) <= 2002){
                                counter++;
                            }
                        }else if(tmpString.find("iyr") != string::npos){
                            tmpNum = tmpString.substr( tmpString.find(":") + 1 , tmpString.size() - tmpString.find(":") );
                            if(stoi (tmpNum) >= 2010 & stoi (tmpNum) <= 2020){
                                counter++;
                            }
                        }else if(tmpString.find("eyr") != string::npos){
                            tmpNum = tmpString.substr( tmpString.find(":") + 1 , tmpString.size() - tmpString.find(":") );
                            if(stoi (tmpNum) >= 2020 & stoi (tmpNum) <= 2030){
                                counter++;
                            }
                        }else if(tmpString.find("hgt") != string::npos){
                            if(tmpString.find("cm") != string::npos){
                                tmpNum = tmpString.substr( tmpString.find(":") + 1 , tmpString.size() - tmpString.find(":") );
                                tmpNum = tmpNum.substr(0,tmpNum.size()-2);
                                if(stoi (tmpNum) >= 150 & stoi (tmpNum) <= 193){
                                    counter++;
                                }
                            }else{
                                tmpNum = tmpString.substr( tmpString.find(":") + 1 , tmpString.size() - tmpString.find(":") );
                                tmpNum = tmpNum.substr(0,tmpNum.size()-2);
                                if(stoi (tmpNum) >= 59 & stoi (tmpNum) <= 76){
                                    counter++;
                                }
                            }
                        }else if(tmpString.find("hcl") != string::npos){
                            vector<string> badLetters{"g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"};
                            if(tmpString.substr(5,1).compare("#")){
                                if( tmpString.substr(5,tmpString.size()-5).size() == 6){
                                    bool checkInt = true;
                                    for (int h = 0; h < badLetters.size(); h++){
                                        if(tmpString.find(badLetters[h]) != string::npos){
                                            checkInt = false;
                                        }
                                    }
                                    if(!checkInt){
                                        counter++;
                                    }
                                }
                            }
                            //a # followed by exactly six characters 0-9 or a-f
                        }else if(tmpString.find("ecl") != string::npos){
                            //exactly one of: amb blu brn gry grn hzl oth.
                        }else if(tmpString.find("pid") != string::npos){
                            //a nine-digit number, including leading zeroes.
                        }                                                               
                    }
                }
            }
            
            if(keywordCounter == 7){
                counter++;
            }

            keywordCounter = 0;
            tmp.clear();
        }
    }

    cout << counter << "\n";
}

int main(){
    vector<string> input;   

    inputToVektor(input);
    solutionPart1(input);
    solutionPart2(input);  

    return 0;
}