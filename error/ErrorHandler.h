//
// Created by Walid on 5/6/2017.
//

#ifndef SIC_ASSEMBLER_ERRORHANDLER_H
#define SIC_ASSEMBLER_ERRORHANDLER_H


#include <string>

class ErrorHandler {
public:
    enum Error {duplicate_label, invalid_label, mnemonic_not_found, invalid_operand,
        missing_operand, multiple_ends, missing_label_at_start,
        label_is_mnemonic, label_at_end, undefined_symbol_at_start ,invalid_source_name,address_out_of_range};
    static const std::string errors[];
};


#endif //SIC_ASSEMBLER_ERRORHANDLER_H
