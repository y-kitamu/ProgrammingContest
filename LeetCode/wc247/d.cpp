/*
 * d.cpp
 *
 * Create Date : 2021-06-27 12:32:59
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


class Solution {
  public:
    static const int MAX = 510000;
    const int MOD = 1000000007;

    long long fac[MAX], finv[MAX], inv[MAX];

    // テーブルを作る前処理
    void COMinit() {
        fac[0] = fac[1] = 1;
        finv[0] = finv[1] = 1;
        inv[1] = 1;
        for (int i = 2; i < MAX; i++) {
            fac[i] = fac[i - 1] * i % MOD;
            inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
            finv[i] = finv[i - 1] * inv[i] % MOD;
        }
    }

    int waysToBuildRooms(std::vector<int>& prevRoom) {
        int n = prevRoom.size();
        std::vector<std::vector<int>> link(n);

        for (int i = 1; i < n; i++) {
            link[prevRoom[i]].emplace_back(i);
        }
        auto res = dfs(0, link);
        return res.second;
    }

    std::pair<long long int, long long int> dfs(int idx, std::vector<std::vector<int>>& link) {
        if (link[idx].size() == 0) {
            return std::make_pair(1, 1);
        }

        int num = 0;
        int cnt = 1;
        for (auto next : link[idx]) {
            auto res = dfs(next, link);
            num += res.first;
            cnt = (res.second * finv[res.first]) % MOD * cnt % MOD;
        }
        cnt = cnt * fac[num] % MOD;
        std::cout << idx << " , " << cnt << " , " << num << std::endl;
        return std::make_pair(num + 1, cnt);
    }
};


int main() {}
