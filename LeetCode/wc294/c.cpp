/**
 * @file c.cpp
 * @brief
 * @author Yusuke Kitamura <ymyk6602@gmail.com>
 * @date 2022-05-22 11:37:03
 */
#include <bits/stdc++.h>


class Solution {
  public:
    int minimumLines(std::vector<std::vector<int>>& stockPrices) {
        std::sort(stockPrices.begin(), stockPrices.end(),
                  [](auto& lhs, auto& rhs) { return lhs[0] < rhs[0]; });
        int n = stockPrices.size();

        int cnt = 0;
        int dx = 0, dy = -2e9;
        for (int i = 0; i < n - 1; i++) {
            auto p1 = stockPrices[i];
            auto p2 = stockPrices[i + 1];
            int x = p2[0] - p1[0];
            int y = p2[1] - p1[1];
            if (y == 0 && dy == 0) {
                continue;
            }
            int g = gcd(x, y);
            x /= g;
            y /= g;
            if (dx != x || dy != y) {
                cnt++;
                dx = x;
                dy = y;
            }
        }
        return cnt;
    }

    int gcd(int x, int y) {
        if (y < 0) {
            y = -y;
        }
        while (y > 0) {
            int tmp = y;
            y = x % y;
            x = tmp;
        }
        return x;
    }
};

int main() {}
