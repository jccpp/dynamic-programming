#include <iostream>
#include <vector>

#include "memo/sum.h"
#include "util/output.h"
#include "util/timer.h"

int main() {

    using namespace out;

    std::cout << "Programación Dinámica\n\n";

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
            timer::Timer timer;
            auto result = f(a.targetSum, a.numbers);
            std::cout << "  " << name
                      << "(" << a.targetSum << ", " << a.numbers << ") = "
                      << std::boolalpha << result << "  (" << timer << ")\n";
        }
        std::cout << '\n';
    };

    std::cout << "canSum with brute force\n";
    execute("canSumBF", memo::canSumBF);

    std::cout << "canSum with memoization\n";
    execute("canSum", memo::canSum);

    std::cout << "howSum with brute force\n";
    execute("howSumBF", memo::howSumBF);

    std::cout << "howSum with memoization\n";
    execute("howSum", memo::howSum);

    std::cout << "bestSum with brute force\n";
    execute("bestSumBF", memo::bestSumBF);

    std::cout << "bestSum with memoization\n";
    execute("bestSum", memo::bestSum);

    return 0;
}