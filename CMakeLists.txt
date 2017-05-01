cmake_minimum_required(VERSION 3.7)
project(SIC_Assembler)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp MainController.cpp MainController.h PassOneController.cpp PassOneController.h PassTwoController.cpp PassTwoController.h)
add_executable(SIC_Assembler ${SOURCE_FILES})