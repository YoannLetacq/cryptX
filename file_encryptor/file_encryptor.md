# FileEncryptor

## Description

`FileEncryptor` est une classe responsable du chiffrement et du déchiffrement d'un fichier binaire à l'aide de l'algorithme XOR.  
L'opération XOR étant symétrique, appliquer cette opération sur un fichier déjà chiffré permet de le déchiffrer.

## Fonctionnalités

- Lecture d'un fichier source en mode binaire.
- Application d'un chiffrement XOR sur chaque octet avec une clé donnée.
- Écriture du résultat dans un fichier de sortie.
- Utilisable pour chiffrer et déchiffrer.

## Interface

- **Constructeur**  
  `explicit FileEncryptor(char key)`  
  Initialise l'instance avec la clé XOR spécifiée.

- **Méthode**  
  `bool processFile(const std::string& inputFile, const std::string& outputFile) const`  
  Lit le fichier `inputFile`, applique XOR sur chaque octet, et écrit le résultat dans `outputFile`.  
  Retourne `true` en cas de succès, `false` en cas d'erreur.

## Exemple d'utilisation

```cpp
FileEncryptor encryptor(0xAA);
if (encryptor.processFile("input.bin", "encrypted.bin")) {
    // Traitement réussi
} else {
    // Gestion de l'erreur
}
```
## Dependances
Bibliothèques standards C++ : `<fstream>`, `<iostream>`, `<string>`
