//
// Created by Salma.Ahmed on 22/05/2017.
//
#include "OrgDirective.h"
#include "../error/ErrorHandler.h"

int OrgDirective::execute(int &start, int &end, int &locationCounter,
                          Operand *operand,  std::map<std::string, int> &symbolTable, std::map<std::string, std::pair<Operand *, int>> &literalTable) {

    /*case 1 ORG without operand resets LC*/
    if (operand->isEmpty() && previousLC!= -1) {
        locationCounter = previousLC;
    }/*case 2 update the location counter with the operand of the org*/
    else if (previousLC == -1){
       locationCounter = locationCounter;
    }else{
        if (operand->isCurrentLocationCounter()) {
            locationCounter = locationCounter;
        } else if (operand->isLabel()) {
            locationCounter = symbolTable[operand->getOperandField()];
        } else if (operand->isFixedAddress()) {
            locationCounter = operand->getLCIncrement();
        } else {
            locationCounter = operand->getExpressionValue();
        }

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


    if (statement->getOperand()->validateCurrentLocationCounter()||statement->getOperand()->validateLabel()
        ||statement->getOperand()->validateDecimalAddress()||statement->getOperand()->validateHexAddress()
        ||statement->getOperand()->validateExpression(symbolTable)) {
        if(statement->getOperand()->isLabel()){
        if (symbolTable.find(statement->getOperand()->getOperandField()) == symbolTable.end()
                ||symbolTable[statement->getOperand()->getOperandField()] == -1 ){
                throw ErrorHandler::org_operand;
            }
        }
    }else{
        throw ErrorHandler::org_operand;
    }
}