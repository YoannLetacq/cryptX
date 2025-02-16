#ifndef FILEENCRYPTOR_H
#define FILEENCRYPTOR_H

#include <string>

class FileEncryptor {
   public:
    // Constructeur qui prend la clé XOR
    explicit FileEncryptor(char key);

    // Méthode qui traite (chiffre ou déchiffre) un fichier en appliquant XOR
    bool processFile(const std::string& inputFile,
                     const std::string& outputFile) const;

   private:
    char key_;  // Clé utilisée pour l'opération XOR
};

#endif

