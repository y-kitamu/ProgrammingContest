/*
 * c.cpp
 *
 * Create Date : 2021-08-29 11:42:59
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


class Solution {
  public:
    int session;

    int minSessions(std::vector<int>& tasks, int sessionTime) {
        session = sessionTime;
        std::sort(tasks.begin(), tasks.end());
        std::vector<std::vector<int>> dp(1 << tasks.size(), std::vector<int>(sessionTime + 1, -1));
        int max = (1 << tasks.size()) - 1;
        for (int i = 0; i <= sessionTime; i++) {
            dp[max][i] = 0;
        }
        return find_best(tasks, 0, sessionTime, dp) + 1;
    }

    int find_best(std::vector<int>& tasks, int flag, int res, std::vector<std::vector<int>>& dp) {
        if (dp[flag][res] >= 0) {
            return dp[flag][res];
        }

        int best = tasks.size();

        for (int idx = 0; idx < tasks.size(); idx++) {
            if ((flag >> idx) & 1) {
                continue;
            }
            if (tasks[idx] <= res) {
                best = std::min(best, find_best(tasks, flag + (1 << idx), res - tasks[idx], dp));
            }
            best = std::min(best, find_best(tasks, flag + (1 << idx), session - tasks[idx], dp) + 1);
        }
        dp[flag][res] = best;
        return best;
    }
};

int main() {}
