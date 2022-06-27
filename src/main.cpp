#include <algorithm>
#include <chrono>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <typeinfo>
#include <vector>

#include "memo/sum.h"

using namespace std::chrono;
typedef high_resolution_clock Clock;

std::ostream &operator<<(std::ostream &out, const std::vector<int> &numbers) {
    out << "[";
    std::copy(numbers.begin(), numbers.end(), std::ostream_iterator<int>(out, ", "));
    out << (!numbers.empty() ? "\b\b" : "") << "]";
    return out;
}

std::ostream &operator<<(std::ostream &out, const std::vector<int> *numbers) {
    if (numbers == nullptr) {
        out << "null";
    } else {
        out << *numbers;
    }
    return out;
}

int main() {
    std::cout << "Programación Dinámica"
              << std::endl
              << std::endl;

    struct Argument {
        int targetSum;
        std::vector<int> numbers;
    };

    auto args = std::vector<Argument>{
        {7, {2, 3}},
        {7, {5, 3, 4, 7}},
        {7, {2, 4}},
        {8, {2, 3, 5}},
        {260, {7, 14}},
    };

    auto execute = [&args](auto name, auto f) {
        for (const auto &a : args) {
            auto start = Clock::now();
            auto result = f(a.targetSum, a.numbers);
            auto end = Clock::now();
            auto duration = duration_cast<milliseconds>(end - start);
            std::cout << "  " << name
                      << "(" << a.targetSum << ", " << a.numbers << ") = "
                      << std::boolalpha
                      << result
                      << "  (" << duration.count() << " ms)." << std::endl;
        }
    };

    std::cout << "canSum with brute force" << std::endl;
    execute("canSumBF", memo::canSumBF);
    std::cout << std::endl;

    std::cout << "canSum with memoization" << std::endl;
    execute("canSum", memo::canSum);
    std::cout << std::endl;

    std::cout << "howSum with brute force" << std::endl;
    execute("howSumBF", memo::howSumBF);
    std::cout << std::endl;

    std::cout << "howSum with memoization" << std::endl;
    execute("howSum", memo::howSum);
    std::cout << std::endl;

    std::cout << "bestSum with brute force" << std::endl;
    execute("bestSumBF", memo::bestSumBF);
    std::cout << std::endl;

    std::cout << "bestSum with memoization" << std::endl;
    execute("bestSum", memo::bestSum);
    std::cout << std::endl;

    return 0;
}