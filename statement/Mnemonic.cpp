//
// Created by Walid on 5/3/2017.
//

#include "Mnemonic.h"

Mnemonic::Mnemonic(std::string mnemonicField) {
    Mnemonic::mnemonicField = mnemonicField;
}

//const std::string &Mnemonic::getMnemonicField() const {
//    return mnemonicField;
//}

void Mnemonic::setMnemonicField(const std::string &mnemonicField) {
    Mnemonic::mnemonicField = mnemonicField;
}

std::string &Mnemonic::getMnemonicField() {
    return  mnemonicField;
}
