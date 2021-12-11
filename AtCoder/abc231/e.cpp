/*
 * e.cpp
 *
 * Create Date : 2021-12-11 21:31:33
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    int N;
    long long int X;
    std::cin >> N >> X;

    std::vector<long long int> A(N);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    if (X == 1) {
        std::cout << 1 << std::endl;
        return 0;
    }

    std::map<long long int, int> cur;
    cur[0] = 0;
    for (int i = 0; i < N - 1; i++) {
        std::map<long long int, int> next;
        for (auto& val : cur) {
            long long int max = A[i + 1] / A[i];
            long long int diff = std::abs(val.first - X);
            long long int res0 = diff % A[i + 1];
            long long int res1 = A[i + 1] - res0;
            long long int cnt0 = res0 / A[i];
            long long int cnt1 = res1 / A[i];
            // std::cout << "i = " << i << ", val.second = " << val.second << ", max = " << max
            //           << ", diff = " << diff << ", res0 = " << res0 << ", res1 = " << res1
            //           << ", cnt0 = " << cnt0 << ", cnt1 = " << cnt1 << std::endl;
            if (cnt0 < max) {
                long long int n1 = val.first + cnt0 * A[i];
                long long int n2 = val.first - cnt0 * A[i];
                if ((n1 - X) % A[i + 1] == 0) {
                    if (next[n1] != 0) {
                        next[n1] = std::min(next[n1], val.second + (int)cnt0);
                    } else {
                        next[n1] = val.second + cnt0;
                    }
                }
                if ((n2 - X) % A[i + 1] == 0) {
                    if (next[n2] != 0) {
                        next[n2] = std::min(next[n2], val.second + (int)cnt0);
                    } else {
                        next[n2] = val.second + cnt0;
                    }
                }
            }
            if (cnt1 < max) {
                long long int n1 = val.first + cnt1 * A[i];
                long long int n2 = val.first - cnt1 * A[i];
                if ((n1 - X) % A[i + 1] == 0) {
                    if (next[n1] != 0) {
                        next[n1] = std::min(next[n1], val.second + (int)cnt1);
                    } else {
                        next[n1] = val.second + cnt1;
                    }
                }
                if ((n2 - X) % A[i + 1] == 0) {
                    if (next[n2] != 0) {
                        next[n2] = std::min(next[n2], val.second + (int)cnt1);
                    } else {
                        next[n2] = val.second + cnt1;
                    }
                }
            }
        }
        cur = next;
    }

    int ans = 1e9;
    for (auto& pair : cur) {
        long long int val = std::abs((pair.first - X) / A[N - 1]) + pair.second;
        if (val < ans) {
            ans = val;
        }
    }
    std::cout << ans << std::endl;
}
