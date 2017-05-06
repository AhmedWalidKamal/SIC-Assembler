//
// Created by Walid on 5/5/2017.
//

#include "MnemonicValidateState.h"
#include "../statement/Statement.h"
#include "EmptyOperandValidateState.h"
#include "SingleOperandValidateState.h"

int MnemonicValidateState::validate(const std::map<std::string, Instruction *> &instructionTable,
//                                    const std::map<std::string, Directive *> &directiveTable,
                                    const std::map<std::string, int> &symbolTable, const int &start, const int &end,
                                    const int &locationCounter, Statement *statement) {
    if (instructionTable.find(statement->getMnemonic()->getMnemonicField()) != instructionTable.end()) {
        //statement->setMnemonicToInstruction();
//        Instruction *s = instructionTable[statement->getMnemonic()->getMnemonicField()];
//        if (instructionTable[statement->getMnemonic()->getMnemonicField()]->getNumberOfOperands() == 0) {
//            return new EmptyOperandValidateState().validate(instructionTable, directiveTable, symbolTable, start, end, locationCounter, statement);
//        } else {
//            return new SingleOperandValidateState().validate(instructionTable, directiveTable, symbolTable, start, end, locationCounter, statement);
//        }
//    } else if (directiveTable[statement->getMnemonic()->getMnemonicField()].exists()) {
//        return directiveTable[statement->getMnemonic()->getMnemonicField()].validate(params);
//    }
//    return  -3; // Mnemonic not found.
}
