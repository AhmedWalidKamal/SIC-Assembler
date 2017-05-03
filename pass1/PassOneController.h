//
// Created by walid on 5/1/2017.
//

#ifndef SIC_ASSEMBLER_PASSONECONTROLLER_H
#define SIC_ASSEMBLER_PASSONECONTROLLER_H


#include <bits/unordered_map.h>
#include <unordered_map>
#include <bits/valarray_before.h>
#include "../file/FileReader.h"

class PassOneController {
public:
    /// initializing private fields
    PassOneController(unordered_map<std::string, std::pair<opCode *, format *>> *instructionTable,
                      unordered_map<std::string, std::hash<std::string>, std::equal_to<std::string>,
                              std::allocator<std::pair<const std::string, _Tp>>> *directiveTable);
    void execute(symTable, fileReader);
private:

    fileReader, instrMap, locationCounter, symTable, dirTable, start, end;
};


#endif //SIC_ASSEMBLER_PASSONECONTROLLER_H
