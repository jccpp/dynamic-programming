#include <chrono>
#include <iomanip>
#include <iostream>
#include <vector>

#include "memo/travel.h"

using namespace std::chrono;
typedef high_resolution_clock Clock;

int main() {
    std::cout << "Programación Dinámica"
              << std::endl
              << std::endl;

    const auto values = std::vector<memo::Grid>{
        memo::Grid{1, 1},
        memo::Grid{2, 3},
        memo::Grid{3, 2},
        memo::Grid{17, 17},
    };

    auto execute = [&values](const char *name, const auto f) {
        for (const auto &a : values) {
            auto start = Clock::now();
            auto result = f(a.m, a.n);
            auto end = Clock::now();
            auto duration = duration_cast<milliseconds>(end - start);
            std::cout << "  " << name
                      << "(" << std::setw(2) << a.m << ", " << std::setw(2) << a.n << ") ="
                      << std::setw(10) << result
                      << "  [" << duration.count() << " ms]" << std::endl;
        }
    };

    std::cout << "Fibonacci with brute force" << std::endl;
    execute("gridTravelBF", memo::gridTravelBF);
    std::cout << std::endl;

    std::cout << "Fibonacci with memoization" << std::endl;
    execute("gridTravel", memo::gridTravel);

    return 0;
}