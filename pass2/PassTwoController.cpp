//
// Created by SalmaAhmed on 5/1/2017.
//

#include "PassTwoController.h"
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

string toLower(string word);

PassTwoController::PassTwoController(string intermediateFile, string programLength, string objectFile) {

    this ->intermediateFile=intermediateFile;
    this ->programLength=programLength;
    this -> outputFile =objectFile;
    this -> objectWriter= new ObjectCodeWriter(objectFile);
}
void PassTwoController::executePass2() {
    string line;
    vector<string> tokens;
    ifstream infile(intermediateFile);
    //gets line by line from the intermediate file.
    while (getline(infile, line))
    {
        istringstream iss(line);
        string token;
        //splits the line by spaces into tokens and put them in a vector
        while(iss >> token) {
           tokens.push_back(token);
        }
        if(toLower(tokens[1])=="start"){
            //tokens[1] is the program name & tokens[2] is the starting address.
            objectWriter ->writeHeader(tokens[0],tokens[2],programLength);
        }
    }
}
string toLower(string word){
    transform(word.begin(),word.end(),word.begin(),::tolower);
    return word;
}
