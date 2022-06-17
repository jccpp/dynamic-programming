#include <chrono>
#include <iomanip>
#include <iostream>
#include <vector>

#include "memo/fib.h"

using namespace std::chrono;
typedef high_resolution_clock Clock;

int main() {
    std::cout << "Programación Dinámica"
              << std::endl
              << std::endl;

    auto ns = std::vector<int>{1, 2, 7, 46};

    auto execute = [](auto &ns, auto f, auto name) {
        for (auto &n : ns) {
            auto start = Clock::now();
            auto result = f(n);
            auto end = Clock::now();
            auto duration = duration_cast<milliseconds>(end - start);
            std::cout << "  " << name
                      << "(" << std::setw(2) << n << ") ="
                      << std::setw(12) << result
                      << "  [" << duration.count() << " ms]" << std::endl;
        }
    };

    std::cout << "Fibonacci with brute force" << std::endl;
    execute(ns, memo::fibBF, "fibBF");
    std::cout << std::endl;

    std::cout << "Fibonacci with memoization" << std::endl;
    execute(ns, memo::fib, "fib");

    return 0;
}