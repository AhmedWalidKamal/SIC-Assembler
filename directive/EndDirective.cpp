//
// Created by Walid on 5/3/2017.
//

#include "EndDirective.h"
#include "../validate/SingleOperandValidateState.h"

int EndDirective :: execute(int& start, int& end, int& locationCounter,int incrementValue) {
    end = locationCounter;
    return 0;
}

//int EndDirective::validate(const std::map<std::string, Instruction *> &instructionTable,
//                           const std::map<std::string, Directive *> &directiveTable,
//                           const std::map<std::string, int> &symbolTable, const int &start, const int &end,
//                           const int &locationCounter, Statement *statement) {
//    if (end != -1) {
//        return error; // multiple ends.
//    }
//    return new SingleOperandValidateState().validate(params);
//}
