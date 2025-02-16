#include <cassert>
#include <iostream>

#include "timer.h"

int main() {
    Timer timer;
    int sleepDuration = 101;  // Durée de la pause en secondes

    std::cout << "[*] Début de la pause de " << sleepDuration << " secondes..."
              << std::endl;
    double elapsed = timer.sleepForSeconds(sleepDuration);
    std::cout << "[*] Temps écoulé : " << elapsed << " secondes." << std::endl;

    // Vérifier que le temps écoulé est au moins égal à la durée demandée
    assert(elapsed >= sleepDuration && "La durée de sommeil est insuffisante.");

    std::cout << "Test Timer réussi : Temps de sommeil validé." << std::endl;
    return 0;
}

