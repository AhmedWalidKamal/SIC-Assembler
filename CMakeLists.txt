cmake_minimum_required(VERSION 3.7)
project(SIC_Assembler)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES InputHandler.cpp MainController.cpp MainController.h pass1/PassOneController.cpp pass1/PassOneController.h pass2/PassTwoController.cpp pass2/PassTwoController.h datatypes/Hexadecimal.cpp datatypes/Hexadecimal.h file/FileReader.cpp file/FileReader.h file/FileWriter.cpp file/FileWriter.h directive/Directive.cpp directive/Directive.h util/Statement.cpp util/Statement.h pass2/ObjectCodeWriter.cpp pass2/ObjectCodeWriter.h format/FormatOne.cpp format/FormatOne.h format/FormatThree.cpp format/FormatThree.h format/FormatFour.cpp format/FormatFour.h format/FormatTwo.cpp format/FormatTwo.h format/Format.cpp format/Format.h testing/test.cpp util/Label.cpp util/Label.h util/Mnemonic.cpp util/Mnemonic.h util/Operand.cpp util/Operand.h util/Comment.cpp util/Comment.h)
add_executable(SIC_Assembler ${SOURCE_FILES})

set_target_properties(SIC_Assembler PROPERTIES LINKER_LANGUAGE CXX)
