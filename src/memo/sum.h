#pragma once

#include <tuple>
#include <vector>

namespace memo {

    /**
     * @brief Returns true if the sum of the numbers in the vector is equal to the target sum.
     *
     * @param targetSum The target sum.
     * @param numbers The numbers to sum.
     * @return True if the sum of the numbers in the vector is equal to the target sum.
     */
    auto canSumBF(int targetSum, const std::vector<int> &numbers) -> bool;

    /**
     * @brief Returns the way to sum the numbers in the vector to the target sum, using memoization.
     *
     * @param targetSum The target sum.
     * @param numbers The numbers to sum.
     * @return The way to sum the numbers in the vector to the target sum.
     */
    auto canSum(int targetSum, const std::vector<int> &numbers) -> bool;

    /**
     * @brief Returns a vector of numbers that sum to the target sum.
     *
     * @param targetSum The target sum.
     * @param numbers The numbers to sum.
     * @return A vector of numbers that sum to the target sum.
     */
    auto howSumBF(int targetSum, const std::vector<int> &numbers) -> std::vector<int> *;

    /**
     * @brief Returns a vector of numbers that sum to the target sum, using memoization.
     *
     * @param targetSum The target sum.
     * @param numbers The numbers to sum.
     * @return A vector of numbers that sum to the target sum.
     */
    auto howSum(int targetSum, const std::vector<int> &numbers) -> std::vector<int> *;

    /**
     * @brief Returns the best way to sum a given target sum.
     *
     * @param targetSum Target sum.
     * @param numbers Numbers to sum.
     * @return std::vector<int>* Best way (shortest way) to sum the target sum.
     */
    auto bestSumBF(int targetSum, const std::vector<int> &numbers) -> std::vector<int> *;

    /**
     * @brief Returns the best way to sum a given target sum, using memoization.
     *
     * @param targetSum Target sum.
     * @param numbers Numbers to sum.
     * @return std::vector<int>* Best way (shortest way) to sum the target sum.
     */
    auto bestSum(int targetSum, const std::vector<int> &numbers) -> std::vector<int> *;

} // namespace memo
