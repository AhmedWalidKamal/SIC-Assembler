#include <string>
#include <fstream>
#include <iostream>
#include <vector>

//std::vector<std::string> readFileToVector(const std::string& filename)
//{
//    std::ifstream source;
//    source.open(filename);
//    std::vector<std::string> lines;
//    std::string line;
//    while (std::getline(source, line))
//    {
//        lines.push_back(line);
//    }
//    return lines;
//}
//
//void displayVector(const std::vector<std::string> v)
//{
//    for (int i(0); i != v.size(); ++i)
//        std::cout << "\n" << v[i];
//}

/// Input Handler is responsible for handling the input commands, like if we wanted to add -help or
/// When the user wants to use -sic or -sicXE, then it passes the source file name to the main controller
/// then the main controller constructs a file reader object with the source file and passes this object to pass1
/// also the main controller constructs a file writer object with the object file and passes it to pass2

int handleOptionsArgs();

void readFile(char *string);

int main(int argc, char **argv) {
    // argv contains possible -commands or file name directly, pass it to main controller and start working.
    if (argc > 1) {
        int fileNameIndex = handleOptionsArgs();
        readFile(argv[fileNameIndex]);
//        std::string charactersFilename(argv[1]);
//        std::vector<std::string> characters = readFileToVector(charactersFilename);
//
//        displayVector(characters);
    } else {
        std::cout << "No filename was entered.";
    }
    return 0;
}

// This function sends the file name to the main controller and calls execute
void readFile(char *string) {

}

// This function is resposible for handling the command line arguments like -sic, -sicXE, -help or other stuff
// and it returns the index of the file name
/// TODO: Implement this.
int handleOptionsArgs() {
    int fileNameIndex = 1;
    return fileNameIndex;
}