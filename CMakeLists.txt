cmake_minimum_required(VERSION 3.7)
project(SIC_Assembler)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_EXE_LINKER_FLAGS -static)

set(SOURCE_FILES InputHandler.cpp MainController.cpp MainController.h pass1/PassOneController.cpp pass1/PassOneController.h pass2/PassTwoController.cpp pass2/PassTwoController.h datatypes/Hexadecimal.cpp datatypes/Hexadecimal.h file/read/FileReader.cpp file/read/FileReader.h directive/Directive.cpp directive/Directive.h statement/Statement.cpp statement/Statement.h testing/test.cpp statement/Label.cpp statement/Label.h statement/Mnemonic.cpp statement/Mnemonic.h statement/Operand.cpp statement/Operand.h statement/Comment.cpp statement/Comment.h file/write/ObjectFileWriter.cpp file/write/ObjectFileWriter.h file/write/IntermediateFileWriter.cpp file/write/IntermediateFileWriter.h file/write/ListingFileWriter.cpp file/write/ListingFileWriter.h directive/StartDirective.cpp directive/StartDirective.h directive/EndDirective.cpp directive/EndDirective.h directive/ByteDirective.cpp directive/ByteDirective.h directive/WordDirective.cpp directive/WordDirective.h directive/ReserveByteDirective.cpp directive/ReserveByteDirective.h directive/ReserveWordDirective.cpp directive/ReserveWordDirective.h directive/OrgDirective.cpp directive/OrgDirective.h directive/EquDirective.h directive/EquDirective.cpp statement/Instruction.cpp statement/Instruction.h util/Initialization.cpp util/Initialization.h statement/util/StatementBuilder.cpp statement/util/StatementBuilder.h statement/util/FixedFormatBuilder.cpp statement/util/FixedFormatBuilder.h validate/LabelValidationState.cpp validate/LabelValidationState.h validate/MnemonicValidateState.cpp validate/MnemonicValidateState.h validate/EmptyOperandValidateState.cpp validate/EmptyOperandValidateState.h validate/SingleOperandValidateState.cpp validate/SingleOperandValidateState.h validate/Regex.cpp validate/Regex.h error/ErrorHandler.cpp error/ErrorHandler.h util/Program.cpp util/Program.h util/StringUtil.h util/StringUtil.cpp file/write/TextRecord.cpp file/write/TextRecord.h)

add_executable(SIC_Assembler ${SOURCE_FILES})

set_target_properties(SIC_Assembler PROPERTIES LINKER_LANGUAGE CXX)
