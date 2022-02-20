/*
 * b.cpp
 *
 * Create Date : 2022-02-20 11:33:40
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};


class Solution {
  public:
    ListNode* mergeNodes(ListNode* head) {
        int sum = 0;
        auto prev = head;
        auto cur = head->next;
        while (cur != nullptr) {
            std::cout << cur->val << std::endl;
            if (cur->val == 0) {
                prev->val = sum;
                sum = 0;
                if (cur->next != nullptr) {
                    prev->next = cur;
                } else {
                    prev->next = nullptr;
                }
                prev = cur;
            }
            sum += cur->val;
            cur = cur->next;
        }
        return head;
    }
};


int main() {}
