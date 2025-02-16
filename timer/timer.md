# Timer

## Description

`Timer` fournit des fonctionnalités de temporisation.  
Cette classe est utilisée pour mettre en pause l'exécution du programme pendant un nombre de secondes donné et mesurer le temps écoulé.

## Fonctionnalités

- Effectue une pause pendant un nombre de secondes spécifié.
- Mesure et retourne le temps réel écoulé durant la pause.

## Interface

- **Méthode**  
  `double sleepForSeconds(int seconds) const`  
  Met en pause le programme pendant `seconds` secondes et retourne le temps écoulé en secondes.

## Exemple d'utilisation

```cpp
Timer timer;
double elapsed = timer.sleepForSeconds(101);
if (elapsed >= 101) {
    // La pause a été respectée
}
```

## Dependances

Bibliothèque standard uniquement.
