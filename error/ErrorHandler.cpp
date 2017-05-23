//
// Created by Walid on 5/6/2017.
//

#include "ErrorHandler.h"

const std::string ErrorHandler::errors[] = {"Duplicate Label!", "Invalid Label!", "Mnemonic not found!",
                                            "Invalid operand!", "Missing Operand!", "Multiple Ends!",
                                            "Missing Label at Start!", "Label is Mnemonic!",
                                            "Label at End!", "Undefined symbol at start!",
                                            "Invalid Source Name!", "Address out of range!",
                                            "Label was not previously declared!",
                                            "Can't Write code after END!", "Multiple Starts", "Memory Limit Exceeded!",
                                            "Code before Start", "Missing Label For Equate!", "Equate Missing Value!",
                                            "Label Before Org!", "LTORG Directive can't have a label.",
                                            "LTORG directive can't have an operand.",
                                            "EQU operand must be previously defined!"};

