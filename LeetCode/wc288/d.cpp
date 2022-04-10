/*
 * d.cpp
 *
 * Create Date : 2022-04-10 12:06:44
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


class Solution {
  public:
    long long maximumBeauty(std::vector<int>& flowers, long long newFlowers, int target, int full,
                            int partial) {
        int N = flowers.size();
        std::sort(flowers.begin(), flowers.end());
        std::vector<long long int> next(N, 0);
        for (int i = 1; i <= N; i++) {
            if (i > 1) {
                next[i - 1] = next[i - 2] + (flowers[i - 1] - flowers[i - 2]) * (i - 1);
            }
            // std::cout << next[i - 1] << " ";
        }
        // std::cout << std::endl;
        std::vector<long long int> req(N + 1, 0);
        for (int i = 1; i <= N; i++) {
            req[i] = req[i - 1] + std::max(0, target - flowers[N - i]);
        }

        // for (auto& val : req) {
        //     std::cout << val << " "
        // }
        // std::cout << std::endl;

        long long int max_score = 0;
        for (int i = 0; i <= N; i++) {
            long long int res = (long long int)newFlowers - req[i];
            // std::cout << "i = " << i << ", res = " << res << std::endl;
            if (res < 0) {
                break;
            }
            if (i == N || res == 0) {
                max_score = std::max(max_score, (long long int)full * i);
                continue;
            }
            int idx = std::distance(next.begin(), std::upper_bound(next.begin(), next.end(), res)) - 1;
            idx = std::min(idx, N - i - 1);
            res -= next[idx];
            long long int mini = std::min((long long int)target - 1, res / (idx + 1) + flowers[idx]);
            max_score = std::max((long long int)mini * partial + (long long int)full * i, max_score);
        }
        return max_score;
    }
};

int main() {}
