//
// Created by Samsung on 06/05/2017.
//

#ifndef SIC_ASSEMBLER_STRINGUTIL_H
#define SIC_ASSEMBLER_STRINGUTIL_H

#include <string>

class StringUtil {

public:
    static std::string fillSpaces(std::string, int length);

    static std::string fillZeros(std::string word, int size);

    static std::string drawLine(int length);

    static std::string toString(int num);
};


#endif //SIC_ASSEMBLER_STRINGUTIL_H
