#include "counter.h"

Counter::Counter() : value_(0) {}

// Incremente le compteur de 1 jusqu'à la limite
void Counter::run(int limit) {
    for (int i = 0; i < limit; i++) {
        ++value_;
    }
}

// Retourne la valeur du compteur
int Counter::getValue() const { return value_; }
