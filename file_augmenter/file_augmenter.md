
## README_FileAugmenter.md

```markdown
# FileAugmenter

## Description

`FileAugmenter` est une classe dédiée à l'ajout de données "junk" à un fichier existant.  
Son rôle est d'augmenter la taille d'un fichier en y ajoutant exactement un nombre spécifié d'octets (dans notre cas, 101 MB).

## Fonctionnalités

- Ouvre un fichier en mode ajout.
- Écrit dans le fichier un tampon de données (par exemple, rempli de zéros) jusqu'à atteindre la taille supplémentaire demandée.
- Utilise une écriture par blocs pour gérer efficacement de grandes quantités de données.

## Interface

- **Méthode**  
  `bool appendJunkData(const std::string& filePath, size_t extraSize) const`  
  Ajoute `extraSize` octets de données junk au fichier spécifié par `filePath`.  
  Retourne `true` si l'opération réussit, `false` sinon.

## Exemple d'utilisation

```cpp
FileAugmenter augmenter;
if (augmenter.appendJunkData("encrypted.bin", 101 * 1024 * 1024)) {
    // Données ajoutées avec succès
} else {
    // Gestion de l'erreur
}
```

## Dépendances
Bibliothèques standard C++ uniquement : `<fstream>`, `<iostream>`, `<string>`, `<vector>`.

