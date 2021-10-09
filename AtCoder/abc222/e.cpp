/*
 * e.cpp
 *
 * Create Date : 2021-10-09 21:38:21
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int dfs(int idx, int parent, int target, std::vector<int>& counts,
        std::vector<std::vector<std::pair<int, int>>>& ll) {
    for (auto& next : ll[idx]) {
        if (next.second == parent) {
            continue;
        }
        if (next.second == target || dfs(next.second, idx, target, counts, ll) == 1) {
            counts[next.first]++;
            return 1;
        }
    }
    return 0;
}


int main() {
    int N, M, K;
    std::cin >> N >> M >> K;

    std::vector<int> a(M);
    for (int i = 0; i < M; i++) {
        std::cin >> a[i];
        a[i]--;
    }

    std::vector<std::vector<std::pair<int, int>>> ll(N);
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        ll[u].emplace_back(std::make_pair(i, v));
        ll[v].emplace_back(std::make_pair(i, u));
    }

    std::vector<int> counts(N - 1);
    for (int i = 0; i < M - 1; i++) {
        dfs(a[i], -1, a[i + 1], counts, ll);
    }

    int sum = 0;
    for (auto& val : counts) {
        sum += val;
        // std::cout << val << " ";
    }
    // std::cout << std::endl;
    // std::cout << sum << std::endl;

    if ((sum + K) % 2 == 1) {
        std::cout << 0 << std::endl;
        return 0;
    }

    if (K < 0) {
        K *= -1;
    }
    int target = (sum + K) / 2;

    long long int MOD = 998244353;
    std::vector<long long int> dp(target + 1, 0);
    dp[0] = 1;
    for (int j = 0; j < N - 1; j++) {
        int cnt = counts[j];
        for (int i = target; i >= cnt; i--) {
            dp[i] = (dp[i] + dp[i - cnt]) % MOD;
        }
    }
    std::cout << dp[target] << std::endl;
}
