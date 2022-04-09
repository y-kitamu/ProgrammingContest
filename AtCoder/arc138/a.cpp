/*
 * a.cpp
 *
 * Create Date : 2022-04-09 20:58:04
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    int N, K;
    std::cin >> N >> K;
    std::vector<long long int> A(N);

    long long min = 2e9;
    long long max = 0;
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
        if (i < K) {
            min = std::min(min, A[i]);
        } else {
            max = std::max(max, A[i]);
        }
    }

    if (min >= max) {
        std::cout << -1 << std::endl;
        return 0;
    }

    std::vector<int> lis, lvs, ris, rvs;
    lis.emplace_back(K - 1);
    lvs.emplace_back(A[K - 1]);
    ris.emplace_back(K);
    rvs.emplace_back(A[K]);
    for (int i = K - 1; i >= 0; i--) {
        if (A[i] < lvs[lvs.size() - 1]) {
            lis.emplace_back(i);
            lvs.emplace_back(A[i]);
        }
    }

    for (int i = K; i < N; i++) {
        if (A[i] > rvs[rvs.size() - 1]) {
            ris.emplace_back(i);
            rvs.emplace_back(A[i]);
        }
    }

    int ans = N;
    for (int i = 0; i < lvs.size(); i++) {
        int idx = std::distance(rvs.begin(), std::upper_bound(rvs.begin(), rvs.end(), lvs[i]));
        if (idx < rvs.size()) {
            ans = std::min(ris[idx] - lis[i], ans);
        }
    }
    for (int i = 0; i < rvs.size(); i++) {
        int idx = std::distance(lvs.begin(), std::lower_bound(lvs.begin(), lvs.end(), rvs[i])) - 1;
        if (idx >= 0) {
            ans = std::min(ris[i] - lis[idx], ans);
        }
    }

    std::cout << ans << std::endl;
}
