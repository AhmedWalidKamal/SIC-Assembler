cmake_minimum_required(VERSION 3.7)
project(SIC_Assembler)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES InputHandler.cpp MainController.cpp MainController.h pass1/PassOneController.cpp pass1/PassOneController.h pass2/PassTwoController.cpp pass2/PassTwoController.h datatypes/Hexadecimal.cpp datatypes/Hexadecimal.h file/read/FileReader.cpp file/read/FileReader.h file/write/FileWriter.cpp file/write/FileWriter.h directive/Directive.cpp directive/Directive.h util/Statement.cpp util/Statement.h format/FormatOne.cpp format/FormatOne.h format/FormatThree.cpp format/FormatThree.h format/FormatFour.cpp format/FormatFour.h format/FormatTwo.cpp format/FormatTwo.h format/Format.cpp format/Format.h testing/test.cpp util/Label.cpp util/Label.h util/Mnemonic.cpp util/Mnemonic.h util/Operand.cpp util/Operand.h util/Comment.cpp util/Comment.h file/write/ObjectFileWriter.cpp file/write/ObjectFileWriter.h file/write/IntermediateFileWriter.cpp file/write/IntermediateFileWriter.h file/write/ListingFileWriter.cpp file/write/ListingFileWriter.h directive/StartDirective.cpp directive/StartDirective.h directive/EndDirective.cpp directive/EndDirective.h directive/ByteDirective.cpp directive/ByteDirective.h directive/WordDirective.cpp directive/WordDirective.h directive/ReserveByteDirective.cpp directive/ReserveByteDirective.h directive/ReserveWordDirective.cpp directive/ReserveWordDirective.h)
add_executable(SIC_Assembler ${SOURCE_FILES})

set_target_properties(SIC_Assembler PROPERTIES LINKER_LANGUAGE CXX)
