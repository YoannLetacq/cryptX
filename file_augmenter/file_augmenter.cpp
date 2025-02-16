#include "file_augmenter.h"

#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

bool FileAugmenter::appendJunkData(const std::string& filePath,
                                   size_t extraSize) const {
    std::ofstream out(filePath, std::ios::app | std::ios::binary);
    if (!out) {
        std::cerr << "Erreur: Impossible d'ouvrir le fichier " << filePath
                  << std::endl;
        return false;
    }

    const size_t chunkSize = 1024 * 1024;  // 1MB
    std::vector<char> buffer(chunkSize, 0);

    size_t written = 0;
    while (written < extraSize) {
        size_t toWrite = std::min(chunkSize, extraSize - written);
        out.write(buffer.data(), toWrite);
        written += toWrite;
    }

    return true;
}

