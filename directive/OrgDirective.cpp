//
// Created by Salma.Ahmed on 22/05/2017.
//
#include "OrgDirective.h"
#include "../error/ErrorHandler.h"

int OrgDirective::execute(int &start, int &end, int &locationCounter,
                          Operand *operand, std::map<std::string, std::pair<Operand *, int>> &literalTable) {

    /*case 1 ORG without operand resets LC*/
    if (operand->isEmpty()) {
        locationCounter = previousLC;
    }/*case 2 update the location counter with the operand of the org*/
    else {
        if(operand->isLabel()){
            locationCounter=operand->getLCIncrement();
        }
        else if(operand->isDecimalValue()){
            locationCounter=operand->getOperandValue();
        }
//        else if(operand is expression){
//            locationCounter=expression value;
//        }

        previousLC = locationCounter;

    }
    return locationCounter;
}

void OrgDirective::validate(std::map<std::string, Instruction *> &instructionTable,
                            std::map<std::string, Directive *> &directiveTable,
                            std::map<std::string, int> &symbolTable, const int &start, const int &end,
                            const int &locationCounter, Statement *statement) {
    if (!statement->getLabel()->isEmpty()) {
        throw ErrorHandler::label_before_org;
    }
}