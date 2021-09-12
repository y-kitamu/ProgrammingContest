/*
 * d.cpp
 *
 * Create Date : 2021-09-12 11:55:03
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


class Solution {
  public:
    std::vector<int> smallestMissingValueSubtree(std::vector<int>& parents, std::vector<int>& nums) {
        int n = nums.size();
        int one = -1;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) {
                one = i;
                break;
            }
        }
        if (one == -1) {
            return std::vector<int>(n, 1);
        }

        std::vector<int> ans(n, 1);
        std::vector<int> path;
        int idx = one;
        path.emplace_back(idx);
        while (parents[idx] != -1) {
            idx = parents[idx];
            path.emplace_back(idx);
        }

        std::set<int> set;
        auto iter = set.begin();
        for (int i = 1; i <= n + 1; i++, iter++) {
            set.insert(iter, i);
        }

        std::vector<std::vector<int>> ll(n);
        for (int i = 1; i < n; i++) {
            ll[parents[i]].emplace_back(i);
        }

        for (int i = 0; i < path.size(); i++) {
            for (auto& c : ll[path[i]]) {
                if (i > 0 && c == path[i - 1]) {
                    continue;
                }
                update_subtree(c, set, nums, ll);
            }
            set.erase(nums[path[i]]);
            ans[path[i]] = *set.begin();
        }
        return ans;
    }

    void update_subtree(int root_idx, std::set<int>& set, std::vector<int>& nums,
                        std::vector<std::vector<int>>& ll) {
        std::queue<int> que;
        que.push(root_idx);
        while (!que.empty()) {
            auto cur = que.front();
            que.pop();
            set.erase(nums[cur]);

            for (auto& next : ll[cur]) {
                que.push(next);
            }
        }
    }
};

int main() {}
