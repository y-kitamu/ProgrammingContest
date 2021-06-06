/*
 * d.cpp
 *
 * Create Date : 2021-06-06 12:00:44
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


class Solution {
  public:
    int minWastedSpace(std::vector<int>& packages, std::vector<std::vector<int>>& boxes) {
        int MOD = 1e9 + 7;
        int n = packages.size();
        std::sort(packages.begin(), packages.end());

        std::vector<long long int> sum(n + 1, 0);
        for (int i = 0; i < n; i++) {
            sum[i + 1] = sum[i] + packages[i];
        }

        long long int ans = -1;

        for (int i = 0; i < boxes.size(); i++) {
            std::sort(boxes[i].begin(), boxes[i].end());

            int b = boxes[i].size();
            if (boxes[i][b - 1] < packages[n - 1]) {
                continue;
            }

            long long int res = 0;
            long long int prev = 0;
            for (auto& val : boxes[i]) {
                long long int dist = std::distance(
                    packages.begin(), std::upper_bound(packages.begin(), packages.end(), val));

                res += (dist - prev) * val - (sum[dist] - sum[prev]);
                prev = dist;
                std::cout << "(" << val << " " << prev << " " << res << "), ";
            }
            std::cout << std::endl;

            if (ans < 0) {
                ans = res;
            } else {
                ans = std::min(ans, res);
            }
        }
        return ans % MOD;
    }
};


int main() {}
