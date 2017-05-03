cmake_minimum_required(VERSION 3.7)
project(SIC_Assembler)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES InputHandler.cpp MainController.cpp MainController.h pass1/PassOneController.cpp pass1/PassOneController.h pass2/PassTwoController.cpp pass2/PassTwoController.h datatypes/Hexadecimal.cpp datatypes/Hexadecimal.h file/FileReader.cpp file/FileReader.h file/FileWriter.cpp file/FileWriter.h directive/Directive.cpp directive/Directive.h util/Statement.cpp util/Statement.h)
add_executable(SIC_Assembler ${SOURCE_FILES})