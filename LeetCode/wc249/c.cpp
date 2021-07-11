/*
 * c.cpp
 *
 * Create Date : 2021-07-11 11:53:20
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


class Solution {
  public:
    std::vector<char> colors{'r', 'g', 'b'};

    int colorTheGrid(int m, int n) {
        std::vector<std::string> cols;
        dfs(m, "", cols);
        std::cout << cols.size() << std::endl;

        std::vector<std::vector<int>> links(cols.size());
        for (int i = 0; i < cols.size(); i++) {
            for (int j = i + 1; j < cols.size(); j++) {
                bool flag = true;
                for (int k = 0; k < m; k++) {
                    flag &= cols[i][k] != cols[j][k];
                }
                if (flag) {
                    links[i].emplace_back(j);
                    links[j].emplace_back(i);
                }
            }
        }

        long long int MOD = 1e9 + 7;
        std::vector<long long int> cur(cols.size(), 1);
        for (int i = 1; i < n; i++) {
            std::vector<long long int> next(cols.size(), 0);
            for (int j = 0; j < cols.size(); j++) {
                for (auto& k : links[j]) {
                    next[k] = (cur[j] + next[k]) % MOD;
                }
            }
            cur = next;
        }

        long long int sum = 0;
        for (auto& val : cur) {
            sum = (sum + val) % MOD;
        }
        return sum;
    }

    void dfs(int m, std::string cur, std::vector<std::string>& cols) {
        int n = cur.length();
        if (n == m) {
            cols.emplace_back(cur);
            return;
        }

        for (auto& c : colors) {
            if (n == 0 || cur[n - 1] != c) {
                dfs(m, cur + c, cols);
            }
        }
    }
};


int main() {}
