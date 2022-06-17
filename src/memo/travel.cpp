#include "travel.h"
#include <map>

namespace memo {

    namespace {
        auto gridTravel(int m, int n, std::map<Grid, long> &memo) -> long {
            auto key = Grid{m, n};
            if (memo.contains(key)) {
                return memo[key];
            }

            if (m == 1 && n == 1) {
                return 1;
            }

            if (m == 0 || n == 0) {
                return 0;
            }

            return memo[key] = gridTravel(m - 1, n, memo) + gridTravel(m, n - 1, memo);
        }
    } // namespace

    auto gridTravelBF(int m, int n) -> long {
        if (m == 1 && n == 1) {
            return 1;
        }

        if (m == 0 || n == 0) {
            return 0;
        }

        return gridTravelBF(m - 1, n) + gridTravelBF(m, n - 1);
    }

    auto gridTravel(int m, int n) -> long {
        std::map<Grid, long> memo;
        return gridTravel(m, n, memo);
    }

} // namespace memo