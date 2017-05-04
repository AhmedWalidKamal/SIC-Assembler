//
// Created by Walid on 5/1/2017.
//

#ifndef SIC_ASSEMBLER_PASSONECONTROLLER_H
#define SIC_ASSEMBLER_PASSONECONTROLLER_H


#include <unordered_map>
#include "../file/read/FileReader.h"
#include "../format/Format.h"
#include "../directive/Directive.h"
#include "../statement/Instruction.h"

class PassOneController {
public:
    PassOneController(std::unordered_map<std::string, Instruction *> &instructionTable,
                          std::unordered_map<std::string, Directive *> &directiveTable);

    std::string execute(std::unordered_map<std::string, int> &symbolTable, FileReader *fileReader);
private:
    std::unordered_map<std::string, Directive *> directiveTable;
    std::unordered_map<std::string, Instruction *> instructionTable;
    int locationCounter, startAddress, endAddress;
};

#endif //SIC_ASSEMBLER_PASSONECONTROLLER_H

