/*
 * a.cpp
 *
 * Create Date : 2022-02-13 20:58:20
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


long long int MOD = 998244353;

long long int dfs(long long int cur, std::map<long long int, long long int>& vals) {
    if (vals.find(cur) != vals.end()) {
        return vals[cur];
    }
    long long int upper = (cur + 1) / 2;
    long long int lower = cur / 2;
    vals[cur] = (dfs(upper, vals) * dfs(lower, vals)) % MOD;
    return vals[cur];
}


int main() {
    long long int X;
    std::cin >> X;

    std::map<long long int, long long int> vals;
    vals[1] = 1;
    vals[2] = 2;
    vals[3] = 3;
    std::cout << dfs(X, vals) << std::endl;
}
