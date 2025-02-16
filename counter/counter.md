# Counter

## Description

`Counter` est une classe simple qui encapsule un compteur.  
Elle est utilisée pour effectuer une opération d'obfuscation en incrémentant une variable de 0 jusqu'à 100001.

## Fonctionnalités

- Initialisation du compteur à zéro.
- Incrémentation du compteur jusqu'à une limite spécifiée.
- Récupération de la valeur actuelle du compteur.

## Interface

- **Constructeur**  
  `Counter()`  
  Initialise le compteur à 0.

- **Méthode**  
  `void run(int limit)`  
  Incrémente le compteur jusqu'à atteindre la valeur `limit`.

- **Méthode**  
  `int getValue() const`  
  Retourne la valeur actuelle du compteur.

## Exemple d'utilisation

```cpp
Counter counter;
counter.run(100001);
std::cout << "Valeur finale du compteur : " << counter.getValue() << std::endl;
```

## Dépendances

Bibliothèques standards uniquement.
