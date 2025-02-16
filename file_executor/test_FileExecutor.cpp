#include <cassert>
#include <iostream>

#include "file_executor.h"

int main() {
    FileExecutor executor;

    // Test 1 : Exécution avec un fichier valide (Notepad)
    std::string validFile = "C:\\Windows\\System32\\notepad.exe";
    std::cout << "[*] Tentative d'exécution du fichier valide: " << validFile
              << std::endl;
    bool resultValid = executor.executeFile(validFile);
    assert(resultValid && "L'exécution du fichier valide a échoué.");
    std::cout << "[+] Exécution du fichier valide réussie." << std::endl;

    // Test 2 : Exécution avec un fichier invalide
    std::string invalidFile = "C:\\chemin\\inexistant.exe";
    std::cout << "[*] Tentative d'exécution du fichier invalide: "
              << invalidFile << std::endl;
    bool resultInvalid = executor.executeFile(invalidFile);
    assert(!resultInvalid &&
           "L'exécution d'un fichier invalide aurait dû échouer.");
    std::cout << "[+] Test pour un fichier invalide réussi." << std::endl;

    std::cout << "Tous les tests de FileExecutor sont passés avec succès."
              << std::endl;
    return 0;
}

