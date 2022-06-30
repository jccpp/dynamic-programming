#pragma once

#include <iomanip>
#include <iostream>
#include <vector>

#include "timer.h"

namespace out {

    inline std::ostream &operator<<(std::ostream &out, const std::vector<int> &numbers) {
        auto size = std::size(numbers);
        out << "[";
        for (auto const &number : numbers) {
            out << number << (--size ? ", " : "");
        }
        out << "]";
        return out;
    }

    inline std::ostream &operator<<(std::ostream &out, const std::vector<int> *numbers) {
        if (numbers == nullptr) {
            out << "null";
        } else {
            out << *numbers;
        }
        return out;
    }

    inline std::ostream &operator<<(std::ostream &out, const timer::Timer &timer) {
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<float> duration = end - timer.start;
        float ms = duration.count() * 1000;
        out << std::fixed << std::setprecision(4) << ms << " ms.";
        return out;
    }
} // namespace out