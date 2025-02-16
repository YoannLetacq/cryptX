#ifndef TIMER_H
#define TIMER_H

#include <chrono>
#include <thread>

class Timer {
   public:
    // Effectue une pause de 'seconds' secondes et retourne le temps écoulé (en
    // secondes)
    double sleepForSeconds(int seconds) const {
        auto start = std::chrono::steady_clock::now();
        std::this_thread::sleep_for(std::chrono::seconds(seconds));
        auto end = std::chrono::steady_clock::now();
        std::chrono::duration<double> elapsed = end - start;
        return elapsed.count();
    }
};

#endif  // TIMER_H

