//
// Created by walid on 5/1/2017.
//

#include <sstream>
#include <algorithm>
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
