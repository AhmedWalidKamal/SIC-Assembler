//
// Created by Walid on 5/1/2017.
//

#ifndef SIC_ASSEMBLER_PASSONECONTROLLER_H
#define SIC_ASSEMBLER_PASSONECONTROLLER_H


#include <unordered_map>
#include <map>
#include "../file/read/FileReader.h"
#include "../format/Format.h"
#include "../directive/Directive.h"
#include "../statement/Instruction.h"
#include "../util/Program.h"

class PassOneController {
public:
    PassOneController(std::map<std::string, Instruction *> &instructionTable,
                          std::map<std::string, Directive *> &directiveTable);

    bool execute(std::map<std::string, int> &symbolTable,
                        FileReader *fileReader, Program *program);
private:
    std::map<std::string, Instruction *> instructionTable;
    std::map<std::string, Directive *> directiveTable;
    int locationCounter, startAddress, endAddress, lineNumber;
};

#endif //SIC_ASSEMBLER_PASSONECONTROLLER_H

