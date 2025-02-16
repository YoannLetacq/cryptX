#include <iostream>

#include "file_manager.h"

int main() {
    // Chemin vers le fichier chiffré et le fichier temporaire déchiffré
    const std::string encryptedFile = "encrypted.bin";
    const std::string decryptedFile = "decrypted_temp.exe";

    // Création d'une instance de FileManager avec la même clé (0xAA)
    FileManager manager(0xAA);

    std::cout << "[*] Début du déchiffrement et exécution..." << std::endl;
    bool result = manager.decryptAndExecute(encryptedFile, decryptedFile);

    if (result) {
        std::cout << "[*] Déchiffrement et exécution réussis." << std::endl;
    } else {
        std::cerr << "[!] Une erreur est survenue lors du déchiffrement ou de "
                     "l'exécution."
                  << std::endl;
    }

    return 0;
}

