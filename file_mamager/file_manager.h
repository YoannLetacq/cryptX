#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include <string>

class FileManager {
   public:
    explicit FileManager(char key);

    bool decryptAndExecute(const std::string& encryptedFile,
                           const std::string& outputFile) const;

   private:
    char key_;
};

#endif  // FILE_MANAGER_H
