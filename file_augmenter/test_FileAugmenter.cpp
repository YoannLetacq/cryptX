#include <cassert>
#include <fstream>
#include <iostream>
#include <vector>

#include "file_augmenter.h"

// Fonction utilitaire pour obtenir la taille d'un fichier
std::streampos getFileSize(const std::string &filePath) {
    std::ifstream in(filePath, std::ios::binary | std::ios::ate);
    return in.tellg();
}

int main() {
    const std::string testFile = "test_file.bin";

    // 1. Création d'un fichier de test avec des données initiales (ex : 1 KB de
    // 'A')
    const size_t initialSize = 1024;  // 1 KB
    std::vector<char> data(initialSize, 'A');
    {
        std::ofstream out(testFile, std::ios::binary);
        assert(out && "Erreur lors de la création du fichier de test.");
        out.write(data.data(), data.size());
    }

    // 2. Mesurer la taille initiale du fichier
    std::streampos originalSize = getFileSize(testFile);

    // 3. Utilisation de FileAugmenter pour ajouter 101 MB
    const size_t extraBytes = 101 * 1024 * 1024;  // 101 MB en octets
    FileAugmenter augmenter;
    bool result = augmenter.appendJunkData(testFile, extraBytes);
    assert(result && "L'ajout des données a échoué.");

    // 4. Vérifier que la nouvelle taille correspond à originalSize + extraBytes
    std::streampos newSize = getFileSize(testFile);
    assert(newSize == originalSize + static_cast<std::streampos>(extraBytes) &&
           "La taille du fichier n'est pas correcte après l'ajout.");

    std::cout << "Test FileAugmenter réussi : taille initiale = "
              << originalSize << " octets, nouvelle taille = " << newSize
              << " octets." << std::endl;

    return 0;
}

