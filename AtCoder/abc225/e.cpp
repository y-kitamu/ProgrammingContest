/*
 * e.cpp
 *
 * Create Date : 2021-10-30 21:54:06
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    int N;
    std::cin >> N;

    std::vector<long long int> max_x(N), max_y(N), min_x(N), min_y(N);
    for (int i = 0; i < N; i++) {
        int x, y;
        std::cin >> x >> y;
        max_x[i] = x - 1;
        max_y[i] = y;
        if ((y - 1) * x > y * (x - 1)) {
            min_x[i] = x;
            min_y[i] = y;
        } else {
            min_x[i] = x - 1;
            min_y[i] = y - 1;
        }
        // std::cout << (double)y / (x - 1) << std::endl;
    }
    std::vector<int> idx(N, 0);
    std::iota(idx.begin(), idx.end(), 0);
    std::sort(idx.begin(), idx.end(), [&max_x, &max_y, &min_x, &min_y](auto& lhs, auto& rhs) {
        if (max_y[lhs] * max_x[rhs] == max_y[rhs] * max_x[lhs]) {
            return min_y[lhs] * min_x[rhs] < min_y[rhs] * min_x[lhs];
        }
        return max_y[lhs] * max_x[rhs] < max_y[rhs] * max_x[lhs];
    });
    int max = 1;
    long long int mx = max_x[idx[0]];
    long long int my = max_y[idx[0]];
    std::vector<int> dp(N, 1);
    for (int i = 1; i < N; i++) {
        long long int x = min_x[idx[i]];
        long long int y = min_y[idx[i]];
        // std::cout << i << " , " << idx[i] << " , " << (double)y / x << std::endl;
        if (y * mx < x * my) {
            continue;
        }
        int imin = 0;
        int imax = i;
        while (imin != imax) {
            int mid = (imin + imax) / 2;
            // std::cout << (double)y / x << " , " << (double)max_y[idx[mid]] / max_x[idx[mid]]
            //           << std::endl;
            if (y * max_x[idx[mid]] >= x * max_y[idx[mid]]) {
                imin = mid + 1;
            } else {
                imax = mid;
            }
        }
        // std::cout << imin << std::endl;
        dp[i] = dp[imin - 1] + 1;
        max = std::max(dp[i], max);
    }
    std::cout << max << std::endl;
}
