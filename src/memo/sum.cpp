#include "sum.h"

#include <iostream>
#include <map>
#include <optional>

namespace memo {

    namespace {

        auto canSum(int targetSum, const std::vector<int> &numbers, std::map<int, bool> &memo) -> bool {
            if (memo.contains(targetSum)) {
                return memo[targetSum];
            }

            if (targetSum == 0) {
                return true;
            }

            if (targetSum < 0) {
                return false;
            }

            for (const auto &number : numbers) {
                if (canSum(targetSum - number, numbers, memo)) {
                    memo[targetSum] = true;
                    return true;
                }
            }

            memo[targetSum] = false;
            return false;
        }

        auto howSum(int targetSum, const std::vector<int> &numbers, std::map<int, std::vector<int> *> &memo) -> std::vector<int> * {
            if (memo.contains(targetSum)) {
                return memo[targetSum];
            }

            if (targetSum == 0) {
                return new std::vector<int>();
            }

            if (targetSum < 0) {
                return nullptr;
            }

            for (const auto &number : numbers) {
                auto way = howSum(targetSum - number, numbers, memo);
                if (way != nullptr) {
                    way->push_back(number);
                    memo[targetSum] = way;
                    return way;
                }
            }
            memo[targetSum] = nullptr;
            return nullptr;
        }

        auto bestSum(int targetSum, const std::vector<int> &numbers, std::map<int, std::vector<int> *> &memo) -> std::vector<int> * {
            if (memo.contains(targetSum)) {
                return memo[targetSum];
            }

            if (targetSum == 0) {
                return new std::vector<int>();
            }

            if (targetSum < 0) {
                return nullptr;
            }

            std::vector<int> *best = nullptr;

            for (const auto &number : numbers) {
                auto way = bestSum(targetSum - number, numbers, memo);
                if (way != nullptr) {
                    way->push_back(number);
                    if (best == nullptr || way->size() < best->size()) {
                        best = way;
                    }
                }
            }
            memo[targetSum] = best;
            return best;
        }
    } // namespace

    auto canSumBF(int targetSum, const std::vector<int> &numbers) -> bool {
        if (targetSum == 0) {
            return true;
        }

        if (targetSum < 0) {
            return false;
        }

        for (const auto &number : numbers) {
            if (canSumBF(targetSum - number, numbers)) {
                return true;
            }
        }
        return false;
    }

    auto canSum(int targetSum, const std::vector<int> &numbers) -> bool {
        std::map<int, bool> memo;
        return canSum(targetSum, numbers, memo);
    }

    auto howSumBF(int targetSum, const std::vector<int> &numbers) -> std::vector<int> * {
        if (targetSum == 0) {
            return new std::vector<int>();
        }

        if (targetSum < 0) {
            return nullptr;
        }

        for (auto number : numbers) {
            auto way = howSumBF(targetSum - number, numbers);
            if (way != nullptr) {
                way->push_back(number);
                return way;
            }
        }
        return nullptr;
    }

    auto howSum(int targetSum, const std::vector<int> &numbers) -> std::vector<int> * {
        std::map<int, std::vector<int> *> memo;
        return howSum(targetSum, numbers, memo);
    }

    auto bestSumBF(int targetSum, const std::vector<int> &numbers) -> std::vector<int> * {
        if (targetSum == 0) {
            return new std::vector<int>();
        }

        if (targetSum < 0) {
            return nullptr;
        }

        std::vector<int> *best = nullptr;

        for (auto number : numbers) {
            auto way = bestSumBF(targetSum - number, numbers);
            if (way != nullptr) {
                way->push_back(number);
                if (best == nullptr || way->size() < best->size()) {
                    delete best;
                    best = way;
                } else {
                    delete way;
                }
            }
        }
        return best;
    }

    auto bestSum(int targetSum, const std::vector<int> &numbers) -> std::vector<int> * {
        std::map<int, std::vector<int> *> memo;
        return bestSum(targetSum, numbers, memo);
    }

} // namespace memo