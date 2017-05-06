//
// Created by Samsung on 06/05/2017.
//

#include "StringUtil.h"

static std:: string StringUtil::toString(int number) {
    std::ostringstream stream;
    stream << number;
    return stream.str();;
}
static std::string StringUtil:: fillSpaces(std::string word,int size){
    while(word.length()<size) {
        word+=" ";
    }
    return word;
}
static string StringUtil:: fillZeros(std::string word,int size){
    while(word.length()<size) {
        word="0"+word;
    }
    return word;
}
static std::string StringUtil:: drawLine(int length){
    std::string line;
    while(length--){
        line+="*";
    }

    return line;
}