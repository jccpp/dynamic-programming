#pragma once
#include <chrono>
#include <iomanip>
#include <iostream>

namespace timer {

    struct Timer {

        std::chrono::time_point<std::chrono::high_resolution_clock> start;

        Timer() {
            start = std::chrono::high_resolution_clock::now();
        }
    };

} // namespace timer