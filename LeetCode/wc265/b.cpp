/*
 * b.cpp
 *
 * Create Date : 2021-10-31 11:32:11
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
  public:
    std::vector<int> nodesBetweenCriticalPoints(ListNode *head) {
        auto cur = head;
        std::vector<int> vals;
        while (cur != nullptr) {
            vals.emplace_back(cur->val);
            cur = cur->next;
        }
        std::vector<int> crits;
        for (int i = 1; i < vals.size() - 1; i++) {
            if (vals[i] > vals[i - 1] && vals[i] > vals[i + 1]) {
                crits.emplace_back(i);
            }
            if (vals[i] < vals[i - 1] && vals[i] < vals[i + 1]) {
                crits.emplace_back(i);
            }
        }
        if (crits.size() < 2) {
            return {-1, -1};
        }
        int max = crits[crits.size() - 1] - crits[0];
        int min = crits[1] - crits[0];
        for (int i = 1; i < crits.size() - 1; i++) {
            min = std::min(crits[i + 1] - crits[i], min);
        }
        return {min, max};
    }
};


int main() {}
