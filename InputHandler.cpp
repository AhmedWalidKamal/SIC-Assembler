#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include "MainController.h"

int handleOptionsArgs(char **pString);
void readFile(std::string fileName);

int main(int argc, char **argv) {
    // argv contains possible -commands or file name directly, pass it to main controller and start working.
//    if (argc > 1) {
//        int fileNameIndex = handleOptionsArgs(argv);
//        readFile(argv[fileNameIndex]);
//    } else {
//        std::cout << "No file name was entered.";
//    }
    readFile("2.asm");
    return 0;
}

void readFile(std::string fileName) {
    MainController *mainController = new MainController();
    mainController->execute(fileName);
}

int handleOptionsArgs(char **arguments) {
    int fileNameIndex = 1;
    return fileNameIndex;
}

