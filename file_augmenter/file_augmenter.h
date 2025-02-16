#ifndef FILE_AUGMENTER_H
#define FILE_AUGMENTER_H

#include <cstddef>
#include <string>

class FileAugmenter {
   public:
    bool appendJunkData(const std::string& filePath, size_t extraSize) const;
};

#endif  // FILE_AUGMENTER_H
