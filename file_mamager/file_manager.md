# FileManager

## Description

`FileManager` orchestre le processus de déchiffrement et d'exécution d'un fichier.  
Il combine les fonctionnalités de `FileEncryptor` et `FileExecutor` pour :
- Déchiffrer un fichier chiffré (via XOR).
- Sauvegarder le fichier déchiffré dans un emplacement temporaire.
- Exécuter le fichier déchiffré en utilisant l'API Windows.

## Fonctionnalités

- Intègre la décryption grâce à `FileEncryptor`.
- Lance l'exécutable déchiffré grâce à `FileExecutor`.
- Gère la communication et le reporting des erreurs durant les deux opérations.

## Interface

- **Constructeur**  
  `explicit FileManager(char key)`  
  Initialise l'instance avec la clé de déchiffrement.

- **Méthode**  
  `bool decryptAndExecute(const std::string& encryptedFile, const std::string& outputFile) const`  
  Déchiffre le fichier `encryptedFile` et enregistre le résultat dans `outputFile`, puis exécute ce dernier.  
  Retourne `true` si les deux opérations réussissent, `false` sinon.

## Exemple d'utilisation

```cpp
FileManager manager(0xAA);
if (manager.decryptAndExecute("encrypted.bin", "decrypted_temp.exe")) {
    // Déchiffrement et exécution réussis
} else {
    // Gestion de l'erreur
}
```

## Dependances

- `FileEncryptor`
- `FileExecutor`
Bibliothèques standard C++.

