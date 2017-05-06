//
// Created by Walid on 5/3/2017.
//

#ifndef SIC_ASSEMBLER_MNEMONIC_H
#define SIC_ASSEMBLER_MNEMONIC_H


#include <string>

class Mnemonic {
public:
    Mnemonic(std::string mnemonicField);
    std::string &getMnemonicField();
    void setMnemonicField(const std::string &mnemonicField);

    /// trim the spaces and check if letter found in place 10
    bool isValid();
private:
    std::string mnemonicField;


};


#endif //SIC_ASSEMBLER_MNEMONIC_H
