#include "file_encryptor.h"

#include <fstream>
#include <iostream>

FileEncryptor::FileEncryptor(char key) : key_(key) {}

bool FileEncryptor::processFile(const std::string& inputFileName,
                                const std::string& outputFileName) const {
    std::ifstream in(inputFileName, std::ios::binary);
    if (!in) {
        std::cerr << "Error opening input file: " << inputFileName << std::endl;
        return false;
    }

    std::ofstream out(outputFileName, std::ios::binary);
    if (!out) {
        std::cerr << "Error opening output file: " << outputFileName
                  << std::endl;
        return false;
    }

    char byte;
    while (in.get(byte)) {
        out.put(byte ^ key_);
    }

    return true;
}
