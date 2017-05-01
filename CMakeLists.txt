cmake_minimum_required(VERSION 3.7)
project(SIC_Assembler)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp MainController.cpp MainController.h pass1/PassOneController.cpp pass1/PassOneController.h pass2/PassTwoController.cpp pass2/PassTwoController.h pass2/ObjectCodeWriter.cpp pass2/ObjectCodeWriter.h)
add_executable(SIC_Assembler ${SOURCE_FILES})

set_target_properties(SIC_Assembler PROPERTIES LINKER_LANGUAGE CXX)