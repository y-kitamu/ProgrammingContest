/**
 * @file c.cpp
 * @brief
 * @author Yusuke Kitamura <ymyk6602@gmail.com>
 * @date 2022-11-06 11:41:29
 */
#include <bits/stdc++.h>


class Solution {
  public:
    long long totalCost(std::vector<int>& costs, int k, int candidates) {
        long long total = 0;
        int left = candidates, right = costs.size() - candidates;
        std::multiset<int> lcands, rcands;
        for (int i = 0; i < left; i++) {
            lcands.insert(costs[i]);
        }
        for (int i = std::max(left, right); i < costs.size(); i++) {
            rcands.insert(costs[i]);
        }
        for (int i = 0; i < k; i++) {
            int lcost = lcands.size() == 0 ? 1e9 : *lcands.begin();
            int rcost = rcands.size() == 0 ? 1e9 : *rcands.begin();
            std::cout << i << ", " << lcost << ", " << rcost << ", " << total << std::endl;
            if (lcost <= rcost) {
                total += lcost;
                lcands.erase(lcands.begin());
                if (left < right) {
                    lcands.insert(costs[left++]);
                }
            } else {
                total += rcost;
                rcands.erase(rcands.begin());
                if (left < right) {
                    rcands.insert(costs[--right]);
                }
            }
        }
        return total;
    }
};


int main(){}
