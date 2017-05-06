//
// Created by user on 5/5/2017.
//

#include "Regex.h"

std::regex Regex :: isEmpty ("\\s*");
std::regex Regex :: isLabel ("[a-zA-Z]\\w{0,7}(\\s+)");
std::regex Regex :: isLabelOperand ("[a-zA-Z]\\w{0,7}(\\s*)");
std::regex Regex :: integerValue("(\\+|-)?[0-9]+(\\s*)");
std::regex Regex :: Indexed(".+,(\\s*)X");
std::regex Regex :: integerAddress("(\\+)?[0-9]+(\\s*)");
std::regex Regex :: hexaAddress("0X'[A-F0-9]+'(\\s*)");
std::regex Regex :: literalString("C'\\w+'(\\s*)");
std::regex Regex :: literalHexa("X'[A-F0-9]+'(\\s*)");
std::regex Regex :: star("\\*(\\s*)");