/*
 * l.cpp
 *
 * Create Date : 2021-08-27 20:57:49
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>

using ll = long long int;

ll solve(int cur, int left, int right, std::vector<std::vector<ll>>& score, std::vector<ll>& a) {
    if (score[left][right] != 1e18) {
        return score[left][right];
    }

    auto lhs = cur * a[left] + solve(-cur, left + 1, right, score, a);
    auto rhs = cur * a[right] + solve(-cur, left, right - 1, score, a);
    if (cur == 1) {
        score[left][right] = std::max(lhs, rhs);
    } else {
        score[left][right] = std::min(lhs, rhs);
    }
    return score[left][right];
}


int main() {
    int N;
    std::cin >> N;
    std::vector<ll> a(N);
    for (int i = 0; i < N; i++) {
        std::cin >> a[i];
    }

    std::vector<std::vector<ll>> score(N, std::vector<ll>(N, 1e18));
    for (int i = 0; i < N; i++) {
        if (N % 2 == 0) {
            score[i][i] = -a[i];
        } else {
            score[i][i] = a[i];
        }
    }
    solve(1, 0, N - 1, score, a);
    // for (auto& vals : score) {
    //     for (auto& val : vals) {
    //         std::cout << val << " ";
    //     }
    //     std::cout << std::endl;
    // }

    std::cout << score[0][N - 1] << std::endl;
}
