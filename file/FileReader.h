//
// Created by walid on 5/2/2017.
//

#ifndef SIC_ASSEMBLER_FILEREADER_H
#define SIC_ASSEMBLER_FILEREADER_H


#include <bits/basic_string.h>
#include <bits/char_traits.h>
#include <bits/allocator.h>
#include <string>

class FileReader {

public:
    FileReader(std::basic_string<char, std::char_traits<char>, std::allocator<char>> basic_string);

private:
    std::string fileName;
};


#endif //SIC_ASSEMBLER_FILEREADER_H
