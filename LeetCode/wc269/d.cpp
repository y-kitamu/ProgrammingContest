/*
 * d.cpp
 *
 * Create Date : 2021-11-28 11:45:30
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


class Solution {
  public:
    std::vector<int> findAllPeople(int n, std::vector<std::vector<int>>& meetings, int firstPerson) {
        std::vector<int> flag(n, 0);
        auto comp = [](auto& lhs, auto& rhs) { return lhs.second > rhs.second; };

        std::vector<std::vector<std::pair<int, int>>> ll(n);
        for (auto& meet : meetings) {
            ll[meet[0]].emplace_back(std::make_pair(meet[1], meet[2]));
            ll[meet[1]].emplace_back(std::make_pair(meet[0], meet[2]));
        }

        auto ll_comp = [](auto& lhs, auto& rhs) { return lhs.second < rhs.second; };
        for (int i = 0; i < n; i++) {
            std::sort(ll[i].begin(), ll[i].end(), ll_comp);
        }

        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(comp)> que{
            comp};
        que.push(std::make_pair(0, 0));
        que.push(std::make_pair(firstPerson, 0));

        while (!que.empty()) {
            auto top = que.top();
            que.pop();

            auto idx = top.first;
            if (flag[idx] == 0) {
                flag[idx] = 1;
                auto itr = std::lower_bound(ll[idx].begin(), ll[idx].end(), top, ll_comp);
                while (itr != ll[idx].end()) {
                    if (flag[itr[0].first] == 0) {
                        que.push(*itr);
                    }
                    itr++;
                }
            }
        }
        std::vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (flag[i]) {
                ans.emplace_back(i);
            }
        }
        return ans;
    }
};

int main() {}
