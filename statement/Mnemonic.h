//
// Created by Walid on 5/3/2017.
//

#ifndef SIC_ASSEMBLER_MNEMONIC_H
#define SIC_ASSEMBLER_MNEMONIC_H


#include <string>

class Mnemonic {
public:
    Mnemonic(std::string mnemonicField);

private:
    std::string mnemonicField;
public:
    const std::string &getMnemonicField() const;

    void setMnemonicField(const std::string &mnemonicField);
};


#endif //SIC_ASSEMBLER_MNEMONIC_H
