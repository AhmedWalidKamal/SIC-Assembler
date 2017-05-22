//
// Created by user on 5/5/2017.
//

#include "Regex.h"

std::regex Regex :: isEmpty ("\\s*");
std::regex Regex :: isLabel ("[a-zA-Z]\\w{0,7}(\\s+)");
std::regex Regex :: isLabelOperand ("[a-zA-Z]\\w{0,7}(\\s*)");
std::regex Regex :: integerValue("(\\+|-)?[0-9]+(\\s*)");
std::regex Regex :: Indexed(".+,(\\s*)[xX]");
std::regex Regex :: integerAddress("(\\+)?[0-9]+(\\s*)");
std::regex Regex :: hexaAddress("0[xX]'[A-F0-9]+'(\\s*)"); // Assumption: any hexadeciaml address should be written in the format 0x'<number>'
std::regex Regex :: literalString("[cC]'.'(\\s*)");
std::regex Regex :: literalHexa("[xX]'[A-F0-9]+'(\\s*)");
std::regex Regex :: star("\\*(\\s*)");
std::regex Regex :: asmFile("(\\w+).asm");
std::regex Regex :: commentOrEmptyLine("((\\s*)(\\.+)(.*))|(\\s*)");