#include "file_manager.h"

#include <iostream>

#include "../file_encryptor/file_encryptor.h"
#include "../file_executor/file_executor.h"

FileManager::FileManager(char key) : key_(key) {}

bool FileManager::decryptAndExecute(const std::string& encryptedFile,
                                    const std::string& outputFile) {
    // dechiffrement du fichier
    FileEncryptor decryptor(key_);
    if (!decryptor.processFile(encryptedFile, outputFile)) {
        std::cerr << "Error decrypting file" << std::endl;
        return false;
    }

    // execution du fichier
    FileExecutor executor;
    if (!executor.executeFile(outputFile)) {
        std::cerr << "Error executing file" << std::endl;
        return false;
    }

    return true;
}
