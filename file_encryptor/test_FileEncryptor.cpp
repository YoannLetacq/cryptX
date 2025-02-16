#include <cassert>
#include <fstream>
#include <iostream>
#include <vector>

#include "file_encryptor.h"
// Fonction utilitaire pour créer un fichier de test avec des données connues
void createTestFile(const std::string& filename,
                    const std::vector<char>& data) {
    std::ofstream out(filename, std::ios::binary);
    assert(out && "Impossible d'ouvrir le fichier de test pour écriture.");
    out.write(data.data(), data.size());
    out.close();
}

// Fonction utilitaire pour lire le contenu complet d'un fichier dans un vector
std::vector<char> readFile(const std::string& filename) {
    std::ifstream in(filename, std::ios::binary);
    assert(in && "Impossible d'ouvrir le fichier de test pour lecture.");
    std::vector<char> data((std::istreambuf_iterator<char>(in)),
                           std::istreambuf_iterator<char>());
    in.close();
    return data;
}

int main() {
    const std::string testInput = "test_input.bin";
    const std::string encryptedFile = "test_encrypted.bin";
    const std::string decryptedFile = "test_decrypted.bin";

    // 1. Création du fichier de test avec des données connues
    std::vector<char> originalData = {'T', 'e', 's', 't', ' ',
                                      'd', 'a', 't', 'a'};
    createTestFile(testInput, originalData);

    // 2. Instanciation de FileEncryptor avec la clé 0xAA
    FileEncryptor encryptor(0xAA);

    // 3. Chiffrement du fichier de test
    bool result = encryptor.processFile(testInput, encryptedFile);
    assert(result && "Le chiffrement a échoué.");

    // 4. Vérification du contenu chiffré
    std::vector<char> encryptedData = readFile(encryptedFile);
    std::vector<char> expectedEncrypted;
    for (char c : originalData) {
        expectedEncrypted.push_back(c ^ 0xAA);
    }
    assert(encryptedData == expectedEncrypted &&
           "Les données chiffrées ne correspondent pas aux attentes.");

    // 5. Déchiffrement (en appliquant de nouveau XOR) du fichier chiffré
    result = encryptor.processFile(encryptedFile, decryptedFile);
    assert(result && "Le déchiffrement a échoué.");

    // 6. Vérification que le fichier déchiffré correspond aux données
    // originales
    std::vector<char> decryptedData = readFile(decryptedFile);
    assert(
        decryptedData == originalData &&
        "Les données déchiffrées ne correspondent pas aux données originales.");

    std::cout << "Tous les tests de FileEncryptor sont passés avec succès."
              << std::endl;
    return 0;
}

