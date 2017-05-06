//
// Created by walid on 5/1/2017.
//

#include <sstream>
#include <algorithm>
#include "Hexadecimal.h"

static std::string Hexadecimal::intToHex(int number) {
    std::ostringstream stream;
    const char *hex = "0123456789ABCDEF";
    while (number > 0) {
        int rem = number % 16;
        stream << hex[rem];
        number = number / 16;
    }
    std::string s(stream.str());
    reverse(s.begin(), s.end());
    return s;
}
static std::string Hexadecimal::stringToHex(std::string s) {
    std::string hex;
    for(int i=0;i<s.length();i++){
        int ascii=(int)s[i];
        hex+=intToHex(ascii);
    }
    return hex;
}
