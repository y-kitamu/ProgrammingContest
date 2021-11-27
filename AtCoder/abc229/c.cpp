/*
 * c.cpp
 *
 * Create Date : 2021-11-27 21:05:58
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    long long int N, W;
    std::cin >> N >> W;
    std::vector<long long int> A(N), B(N);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i] >> B[i];
    }

    std::vector<int> idx(N);
    std::iota(idx.begin(), idx.end(), 0);
    std::sort(idx.begin(), idx.end(), [&A](auto& lhs, auto& rhs) { return A[lhs] > A[rhs]; });

    long long int ans = 0;
    int ci = 0;
    while (W > 0 && ci < N) {
        int i = idx[ci++];
        long long int w = std::min(B[i], W);
        ans += w * A[i];
        W -= w;
    }
    std::cout << ans << std::endl;
}
