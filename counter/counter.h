#ifndef COUNTER_H
#define COUNTER_H

class Counter {
   public:
    Counter();

    // Methode qui incremente le compteur jusqu'a la limite
    void run(int limit);

    // retourne la valeur actuelle du compteur
    int getValue() const;

   private:
    int value_;
};

#endif  // COUNTER_H
