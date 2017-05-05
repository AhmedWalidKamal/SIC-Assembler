//
// Created by Samsung on 06/05/2017.
//

#ifndef SIC_ASSEMBLER_STRINGUTIL_H
#define SIC_ASSEMBLER_STRINGUTIL_H

#include <string>

class StringUtil {

public:
    std::string fillSpaces(std::string,int length);
    std::string fillZeros(std::string word,int size);
    std::string drawLine(int length);
    std::string toString(int num);
};


#endif //SIC_ASSEMBLER_STRINGUTIL_H
