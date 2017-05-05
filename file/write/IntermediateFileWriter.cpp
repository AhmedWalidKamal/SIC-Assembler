//
// Created by Walid on 5/3/2017.
//

#include "IntermediateFileWriter.h"

IntermediateFileWriter::IntermediateFileWriter(const std::string &fileName, const std::string fileExtension)
        : fileName(fileName), fileExtension(fileExtension) {
    // Check this or change it whatever, just open a file with the file name and extension for writing.
    IntermediateFileWriter::outputFileStream.open(std::string(fileName).append(fileExtension));
}

/// Writes line to intermediate file, uses helper functions or something.
void IntermediateFileWriter::writeLine(std::string line) {

}
