//
// Created by walid on 5/1/2017.
//

#ifndef SIC_ASSEMBLER_HEXADECIMAL_H
#define SIC_ASSEMBLER_HEXADECIMAL_H


#include <string>

class Hexadecimal {
public:
    static std::string intToHex(int number);

    static std::string stringToHex(std::string s);

    static unsigned long hexToInt(std::string hexadecimal);
};


#endif //SIC_ASSEMBLER_HEXADECIMAL_H
