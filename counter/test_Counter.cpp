#include <cassert>
#include <iostream>

#include "counter.h"

int main() {
    Counter counter;
    // Incrémente jusqu'à 100001
    counter.run(100001);

    // Vérification que le compteur a bien atteint 100001
    assert(counter.getValue() == 100001 &&
           "Le compteur n'a pas atteint la valeur attendue.");

    std::cout << "Test Counter réussi : compteur = " << counter.getValue()
              << std::endl;
    return 0;
}

