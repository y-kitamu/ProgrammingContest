/*
 * f.cpp
 *
 * Create Date : 2022-02-05 22:10:40
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


std::vector<int> index_sort(std::vector<int>& vals) {
    std::vector<int> idx(vals.size(), 0);
    std::iota(idx.begin(), idx.end(), 0);
    std::sort(idx.begin(), idx.end(), [vals](auto& lhs, auto& rhs) { return vals[lhs] < vals[rhs]; });
    return idx;
}

int main() {
    long long int mod = 998244353;
    int N, K;
    std::cin >> N >> K;

    std::vector<int> X(N), Y(N);
    std::vector<int> P(N), Q(N);
    for (int i = 0; i < N; i++) {
        std::cin >> P[i];
        X[--P[i]] = i;
    }
    for (int i = 0; i < N; i++) {
        std::cin >> Q[i];
        Y[--Q[i]] = i;
    }

    auto x_sidx = index_sort(X);
    auto y_sidx = index_sort(Y);

    long long int ans = 0;
    for (int x = N - 1; x >= 0; x--) {
        int x_idx = x_sidx[x];
        for (int y = N - 1; y >= 0; y--) {
            int y_idx = y_sidx[y];

            if (X[x_idx] < X[y_idx] || Y[y_idx] < Y[x_idx]) {
                continue;
            }
            int cnt_out = 0;
            int cnt_in = 0;
            int cnt_mid = 0;
            int max_x = X[x_idx];
            int max_y = Y[y_idx];

            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    if (X[i] >= max_x && Y[i] >= max_y) {
                        cnt_out++;
                    } else if (X[i] >= max_x || Y[i] >= max_y) {
                        cnt_mid++;
                    } else {
                        cnt_in++;
                    }
                }
            }
            if (cnt_in > N) {
                continue;
            }
            long long int res = N - cnt_in;
            if (cnt_mid < res) {
                continue;
            }
            ans = (ans + res * (res - 1) / 2) % mod;
        }
    }
    std::cout << ans << std::endl;
}
