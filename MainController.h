//
// Created by walid on 5/1/2017.
//

#ifndef SIC_ASSEMBLER_MAINCONTROLLER_H
#define SIC_ASSEMBLER_MAINCONTROLLER_H

#include <unordered_map>
#include <string>
#include "file/FileWriter.h"
#include "file/FileReader.h"
#include "directive/Directive.h"
#include "pass1/PassOneController.h"
#include "format/Format.h"

class MainController {
public:
    MainController();

    void execute(std::string fileName);

private:

    std::unordered_map<std::string, Directive *> directiveTable;
    std::unordered_map<std::string, std::pair<int, Format *> > instructionTable;
    std::unordered_map<std::string, int> symbolTable;
    FileReader *sourceFileReader;
    FileWriter *objectFileWriter;

    void setSourceFileReader(std::string fileName);

    void initDirectiveTable(std::unordered_map<std::string, Directive *> &directiveTable);

    void initInstructionTable(std::unordered_map<std::string, std::pair<int, Format *>> &instructionTable);
};


#endif //SIC_ASSEMBLER_MAINCONTROLLER_H
