/*
 * b.cpp
 *
 * Create Date : 2021-12-05 11:37:43
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
  public:
    ListNode* deleteMiddle(ListNode* head) {
        auto cur = head;
        int cnt = 0;
        std::vector<int> vals(2e5, 0);
        int idx = 0;
        while (cur != nullptr) {
            cnt++;
            vals[idx++] = cur->val;
            cur = cur->next;
        }
        if (cnt == 1) {
            return nullptr;
        }
        int mid = cnt / 2;

        auto ans = new ListNode(vals[0]);
        cur = ans;
        for (int i = 1; i < idx; i++) {
            if (i == mid) {
                continue;
            }
            auto n = new ListNode(vals[i]);
            cur->next = n;
            cur = n;
        }

        return ans;
    }
};

int main() {}
