# FileExecutor

## Description

`FileExecutor` est responsable de l'exécution d'un fichier exécutable à l'aide de l'API Windows.  
Il utilise `ShellExecuteA` pour lancer le fichier spécifié.

## Fonctionnalités

- Exécute un fichier en utilisant l'application ou l'association par défaut.
- Retourne un indicateur de succès en fonction du résultat de l'exécution.

## Interface

- **Méthode**  
  `bool executeFile(const std::string& filePath) const`  
  Tente d'exécuter le fichier situé à `filePath`.  
  Retourne `true` en cas de succès et `false` en cas d'échec.

## Exemple d'utilisation

```cpp
FileExecutor executor;
if (executor.executeFile("decrypted_temp.exe")) {
    // Exécution réussie
} else {
    // Gestion de l'erreur
}
```

## Dependances

API Windows : `windows.h`
Bibliotheque standard C++.
