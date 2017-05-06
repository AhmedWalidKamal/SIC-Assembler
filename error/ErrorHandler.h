//
// Created by Walid on 5/6/2017.
//

#ifndef SIC_ASSEMBLER_ERRORHANDLER_H
#define SIC_ASSEMBLER_ERRORHANDLER_H


#include <string>

class ErrorHandler {
public:
    enum Error {duplicate_label, invalid_label, mnemonic_not_found, invalid_operand,
        missing_operand, multiple_ends, missing_label_at_start, label_is_mnemonic};
    static const std::string errors[];
};


#endif //SIC_ASSEMBLER_ERRORHANDLER_H
