/*
 * d.cpp
 *
 * Create Date : 2021-08-29 21:09:29
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


bool dfs(int idx, std::vector<int>& seen, std::vector<int>& finished,
         std::vector<std::vector<int>>& ll) {
    bool flag = true;
    seen[idx] = 1;
    for (auto& next : ll[idx]) {
        if (finished[next] == 1) {
            continue;
        }
        if (seen[next] && !finished[idx]) {
            return false;
        }
        flag &= dfs(next, seen, finished, ll);
        if (!flag) {
            break;
        }
    }

    finished[idx] = 1;
    return flag;
}


int main() {
    int N, M;
    std::cin >> N >> M;

    std::vector<std::vector<int>> ll(N);
    std::vector<int> starts(M);
    for (int i = 0; i < M; i++) {
        int k;
        std::cin >> k;
        std::vector<int> a(k);
        for (int j = 0; j < k; j++) {
            std::cin >> a[j];
            a[j]--;
            if (j > 0) {
                ll[a[j - 1]].emplace_back(a[j]);
            }
        }
        starts[i] = a[0];
    }

    std::vector<int> seen(N, 0), finished(N, 0);

    for (auto& start : starts) {
        if (finished[start] == 1) {
            continue;
        }

        if (!dfs(start, seen, finished, ll)) {
            std::cout << "No" << std::endl;
            return 0;
        }
    }
    std::cout << "Yes" << std::endl;
}
