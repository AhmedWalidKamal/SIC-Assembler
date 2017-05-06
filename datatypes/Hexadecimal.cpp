//
// Created by walid on 5/1/2017.
//

#include <sstream>
#include <algorithm>
#include "Hexadecimal.h"

std::string Hexadecimal::intToHex(int number) {
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

std::string Hexadecimal::stringToHex(std::string s) {
    std::string hex;
    for (int i = 0; i < s.length(); i++) {
        int ascii = (int) s[i];
        hex += intToHex(ascii);
    }
    return hex;
}

unsigned long::Hexadecimal::hexToInt(std::string hex)
{
    unsigned long integer = 0;
    float base=16.0;
    for (int i=0; i<hex.length(); i++) {
        if (hex[i]>=48 && hex[i]<=57)
        {
            integer += (hex[i]-48)*pow(base,hex.length()-i-1);
        } else if (hex[i]>=65 && hex[i]<=70) {
            integer += (hex[i]-55)*pow(base,hex.length( )-i-1);
        } else if (hex[i]>=97 && hex[i]<=102) {
            integer += (hex[i]-87)*pow(base,hex.length()-i-1);
        }
    }
    return integer;
}
