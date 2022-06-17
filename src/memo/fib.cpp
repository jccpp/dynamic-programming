#include "fib.h"

#include <map>

namespace memo {

    namespace {

        long fib(int n, std::map<int, int> &memo) {
            if (memo.find(n) != memo.end()) {
                return memo[n];
            }
            if (n <= 2) {
                return 1;
            }

            int result = fib(n - 1, memo) + fib(n - 2, memo);
            memo[n] = result;
            return result;
        }

    } // namespace

    auto fibBF(int n) -> long {
        if (n <= 2) {
            return 1;
        }
        return fibBF(n - 1) + fibBF(n - 2);
    }

    auto fib(int n) -> long {
        std::map<int, int> memo;
        return fib(n, memo);
    }

} // namespace memo