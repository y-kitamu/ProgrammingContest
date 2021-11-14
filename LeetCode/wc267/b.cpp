/*
 * b.cpp
 *
 * Create Date : 2021-11-14 11:36:22
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
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        std::vector<int> vals(2e5, -1);
        int cnt = 0;
        auto cur = head;
        while (cur != nullptr) {
            vals[cnt++] = cur->val;
            cur = cur->next;
        }

        int gsi = 0;  // group start idx
        int gei = 1;  // group end idx
        cur = head;
        for (int i = 0; i < cnt; i++) {
            if (i == gei) {
                int diff = gei - gsi;
                gsi = gei;
                gei = std::min(gsi + diff + 1, cnt);
            }
            if ((gei - gsi) % 2 == 0) {
                cur->val = vals[gsi - (i - gei) - 1];
            }
            cur = cur->next;
        }
        return head;
    }
};


int main() {}
