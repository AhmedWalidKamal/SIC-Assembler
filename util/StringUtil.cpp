//
// Created by Samsung on 06/05/2017.
//

#include <sstream>
#include "StringUtil.h"

std::string StringUtil::toString(int number) {
    std::ostringstream stream;
    stream << number;
    return stream.str();;
}

std::string StringUtil::fillSpaces(std::string word, int size) {
    while (word.length() < size) {
        word += " ";
    }
    return word;
}

std::string StringUtil::fillZeros(std::string word, int size) {
    while (word.length() < size) {
        word = "0" + word;
    }
    return word;
}

std::string StringUtil::drawLine(int length) {
    std::string line;
    while (length--) {
        line += "*";
    }
    return line;
}
