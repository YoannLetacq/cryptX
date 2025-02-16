#include "file_executor.h"

#include <windows.h>

#include <iostream>

bool FileExecutor::executeFile(const std::string& filePath) const {
    HINSTANCE result = ShellExecuteA(nullptr, "open", filePath.c_str(), nullptr,
                                     nullptr, SW_SHOW);
    if (reinterpret_cast<int>(result) <= 32) {
        std::cerr << "Erreur lors de l'execution du fichier " << filePath
                  << std::endl;
        return false;
    }
    return true;
}
