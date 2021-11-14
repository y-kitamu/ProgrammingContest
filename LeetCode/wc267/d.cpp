/*
 * d.cpp
 *
 * Create Date : 2021-11-14 12:08:25
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


class Solution {
  public:
    std::vector<bool> friendRequests(int n, std::vector<std::vector<int>>& restrictions,
                                     std::vector<std::vector<int>>& requests) {
        std::vector<std::set<int>> bans(n);
        std::vector<std::set<int>> friends(n);
        for (auto& res : restrictions) {
            bans[res[0]].insert(res[1]);
            bans[res[1]].insert(res[0]);
        }
        for (int i = 0; i < n; i++) {
            friends[i].insert(i);
        }

        std::vector<int> roots(n);
        std::iota(roots.begin(), roots.end(), 0);
        auto find_root = [&roots](int idx) {
            std::vector<int> updates;
            while (roots[idx] != idx) {
                updates.emplace_back(idx);
                idx = roots[idx];
            }
            for (auto& upd : updates) {
                roots[upd] = idx;
            }
            return idx;
        };

        int m = requests.size();
        std::vector<bool> ans(m, true);
        for (int i = 0; i < m; i++) {
            auto req = requests[i];
            int lr = find_root(req[0]);
            int rr = find_root(req[1]);

            if (lr == rr) {
                continue;
            }
            for (auto& f : friends[lr]) {
                if (bans[rr].find(f) != bans[rr].end()) {
                    ans[i] = false;
                    break;
                }
            }
            for (auto& f : friends[rr]) {
                if (bans[lr].find(f) != bans[lr].end()) {
                    ans[i] = false;
                    break;
                }
            }
            if (ans[i]) {
                roots[rr] = lr;
                friends[lr].insert(rr);
                friends[rr].insert(lr);
                for (auto& f : friends[rr]) {
                    friends[lr].insert(f);
                }
                for (auto& b : bans[rr]) {
                    bans[lr].insert(b);
                }
            }
        }
        return ans;
    }
};


int main() {}
