/*
 * e.cpp
 *
 * Create Date : 2021-11-07 21:33:37
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


long long int mod_pow(long long int n, long long int r, long long int mod) {
    long long int ans = 1;
    long long int pow = n;
    while (r > 0) {
        if (r & 1) {
            ans = (ans * pow) % mod;
        }
        pow = (pow * pow) % mod;
        r >>= 1;
    }
    return ans;
}


int main() {
    long long int MOD = 998244353;
    int N, M;
    std::cin >> N >> M;


    std::vector<int> roots(N);
    std::iota(roots.begin(), roots.end(), 0);

    auto find_root = [&roots](int idx) {
        std::vector<int> updates;
        while (roots[idx] != idx) {
            updates.emplace_back(idx);
            idx = roots[idx];
        }
        for (auto& val : updates) {
            roots[val] = idx;
        }
        return idx;
    };

    std::vector<std::vector<int>> ll(N);
    for (int i = 0; i < M; i++) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        int ru = find_root(u);
        int rv = find_root(v);
        roots[rv] = ru;
        ll[u].emplace_back(v);
        ll[v].emplace_back(u);
    }

    if (N != M) {
        std::cout << 0 << std::endl;
        return 0;
    }

    std::map<int, std::vector<int>> map;
    for (int i = 0; i < N; i++) {
        int val = find_root(i);
        if (map.find(val) == map.end()) {
            map[val] = std::vector<int>(2, 0);
        }
        map[val][0]++;
        map[val][1] += ll[i].size();
    }

    for (auto& vals : map) {
        if (vals.second[0] * 2 != vals.second[1]) {
            std::cout << 0 << std::endl;
            return 0;
        }
    }

    long long int ans = mod_pow(2, map.size(), MOD);
    std::cout << ans << std::endl;
}
