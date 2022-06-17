#pragma once

namespace memo {
    auto gridTravelBF(int m, int n) -> long;
    auto gridTravel(int m, int n) -> long;

    struct Grid {
        int m;
        int n;

        bool operator==(const Grid &other) const {
            return m == other.m && n == other.n;
        }

        bool operator<(const Grid &other) const {
            return m < other.m || (m == other.m && n < other.n);
        }
    };
} // namespace memo
