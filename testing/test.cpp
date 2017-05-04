//
// Created by Walid on 5/3/2017.
//
#include <iostream>
#include "../file/read/FileReader.h"

int main() {
    // File name should be with a relative path.
    //std::string fileName = "sicEx.asm";
    //FileReader *fileReader = new FileReader(fileName);
    int a = 0x1009;
    int b = 0x03;
    int c = a + b;
    std::cout << std::hex << c;
}
