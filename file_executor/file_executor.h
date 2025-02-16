#ifndef FILE_EXECUTOR_H
#define FILE_EXECUTOR_H

#include <string>

class FileExecutor {
   public:
    bool executeFile(const std::string& filePath) const;
};

#endif  // FILE_EXECUTOR_H
