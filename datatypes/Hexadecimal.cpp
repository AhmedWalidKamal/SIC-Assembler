//
// Created by walid on 5/1/2017.
//

#include <sstream>
#include <algorithm>
#include <math.h>
#include "Hexadecimal.h"
using namespace std;

string Hexadecimal::intToHex(int number) {
    ostringstream stream;
    const char *hex = "0123456789ABCDEF";
    while (number > 0) {
        int rem = number % 16;
        stream << hex[rem];
        number = number / 16;
    }
    string s(stream.str());
    reverse(s.begin(), s.end());
    return s;
}

unsigned long Hexadecimal::hexTodecimal(string hex) {
        unsigned long result = 0;
        for (int i=0; i<hex.length(); i++) {
            if (hex[i]>=48 && hex[i]<=57)
            {
                result += (hex[i]-48)*pow(16,hex.length()-i-1);
            } else if (hex[i]>=65 && hex[i]<=70) {
                result += (hex[i]-55)*pow(16,hex.length( )-i-1);
            } else if (hex[i]>=97 && hex[i]<=102) {
                result += (hex[i]-87)*pow(16,hex.length()-i-1);
            }
        }
        return result;
}
