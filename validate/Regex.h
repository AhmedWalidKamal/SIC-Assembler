//
// Created by user on 5/5/2017.
//

#ifndef SIC_ASSEMBLER_REGEX_H
#define SIC_ASSEMBLER_REGEX_H
#include <regex>
#include <string>

class Regex {

 public :

    static std::regex isEmpty;
    static std::regex isLabel;
    static std::regex integerValue;
    static std::regex integerAddress;
    static std::regex hexaAddress;
    static std::regex Indexed;
    static std::regex literalString;
    static std::regex literalHexa;
    static std::regex star;
    static std::regex isLabelOperand;
    static std::regex asmFile;
    static std::regex commentOrEmptyLine;
};


#endif //SIC_ASSEMBLER_REGEX_H
