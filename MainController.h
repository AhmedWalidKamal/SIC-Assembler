//
// Created by walid on 5/1/2017.
//

#ifndef SIC_ASSEMBLER_MAINCONTROLLER_H
#define SIC_ASSEMBLER_MAINCONTROLLER_H

#include <unordered_map>
#include <string>
#include "file/read/FileReader.h"
#include "directive/Directive.h"
#include "pass1/PassOneController.h"
#include "statement/Instruction.h"
#include "file/write/ObjectFileWriter.h"
#include "file/write/IntermediateFileWriter.h"
#include "file/write/ListingFileWriter.h"

class MainController {
public:
    MainController();

    void execute(std::string fileName);

private:

    std::map<std::string, Instruction *> instructionTable;
    std::map<std::string, Directive *> directiveTable;
    std::map<std::string, int> symbolTable;
    std::map<std::string, std::pair<int, int> > literalTable;
    FileReader *sourceFileReader;

    void setSourceFileReader(std::string fileName);
    void initDirectiveTable(std::map<std::string, Directive *> &directiveTable);
    void initInstructionTable(std::map<std::string, Instruction *> &instructionTable);
};


#endif //SIC_ASSEMBLER_MAINCONTROLLER_H

