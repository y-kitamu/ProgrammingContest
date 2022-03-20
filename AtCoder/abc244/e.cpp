/*
 * e.cpp
 *
 * Create Date : 2022-03-20 21:20:41
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    int N, M, K, S, T, X;
    std::cin >> N >> M >> K >> S >> T >> X;
    S--, T--, X--;

    std::vector<std::vector<int>> edges(M, std::vector<int>(2));
    for (int i = 0; i < M; i++) {
        std::cin >> edges[i][0] >> edges[i][1];
        edges[i][0]--, edges[i][1]--;
    }

    long long int MOD = 998244353;
    std::vector<std::vector<long long int>> cnts(N, std::vector<long long int>(2, 0));
    cnts[S][0] = 1;

    for (int i = 0; i < K; i++) {
        std::vector<std::vector<long long int>> next(N, std::vector<long long int>(2, 0));

        for (auto& edge : edges) {
            if (edge[0] == X) {
                next[edge[0]][0] = (next[edge[0]][0] + cnts[edge[1]][1]) % MOD;
                next[edge[0]][1] = (next[edge[0]][1] + cnts[edge[1]][0]) % MOD;
            } else {
                next[edge[0]][0] = (next[edge[0]][0] + cnts[edge[1]][0]) % MOD;
                next[edge[0]][1] = (next[edge[0]][1] + cnts[edge[1]][1]) % MOD;
            }

            if (edge[1] == X) {
                next[edge[1]][0] = (next[edge[1]][0] + cnts[edge[0]][1]) % MOD;
                next[edge[1]][1] = (next[edge[1]][1] + cnts[edge[0]][0]) % MOD;
            } else {
                next[edge[1]][0] = (next[edge[1]][0] + cnts[edge[0]][0]) % MOD;
                next[edge[1]][1] = (next[edge[1]][1] + cnts[edge[0]][1]) % MOD;
            }
        }
        cnts = next;
    }

    std::cout << cnts[T][0] << std::endl;
}
