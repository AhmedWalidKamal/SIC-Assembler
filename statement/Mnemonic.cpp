//
// Created by Walid on 5/3/2017.
//

#include <algorithm>
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
    return mnemonicField;
}

bool Mnemonic::isValid() {
    bool Valid;
    Valid = mnemonicField.front() != ' ';
    if (Valid) {
        std::transform(mnemonicField.begin(), mnemonicField.end(), mnemonicField.begin(),
                       [](unsigned char c) { return std::toupper(c); });
        std::size_t found = mnemonicField.find_first_of(" ");
            mnemonicField = mnemonicField.substr(0,found);
    }
    return Valid;
}
