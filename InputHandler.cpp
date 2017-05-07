#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include "MainController.h"

/// Input Handler is responsible for handling the input commands, like if we wanted to add -help or
/// When the user wants to use -sic or -sicXE, then it passes the source file name to the main controller
/// then the main controller constructs a file reader object with the source file and passes this object to pass1
/// also the main controller constructs a file writer object with the object file and passes it to pass2

int handleOptionsArgs(char **pString);
void readFile(std::string fileName);

int main(int argc, char **argv) {
    // argv contains possible -commands or file name directly, pass it to main controller and start working.
    /*if (argc > 1) {
        int fileNameIndex = handleOptionsArgs(argv);
        readFile(argv[fileNameIndex]);
    } else {
        std::cout << "No file name was entered.";
    }*/
    readFile("sicEx_1.asm");
//    readFile("errors.asm");
    return 0;
}

// This function sends the file name to the main controller and calls execute
void readFile(std::string fileName) {
    MainController *mainController = new MainController();
    mainController->execute(fileName);
}

// This function is responsible for handling the command line arguments like -sic, -sicXE, -help or other stuff
// and it returns the index of the file name or exits program if user wanted help manual or something.
/// TODO: Implement this.
int handleOptionsArgs(char **arguments) {
    int fileNameIndex = 1;
    return fileNameIndex;
}