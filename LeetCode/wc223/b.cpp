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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* lhs = head;
        for (int i = 0; i < k; i++) {
            lhs = lhs->next;
        }
        int cnt = 1;
        ListNode* rhs = head;
        while (rhs->next != nullptr) {
            rhs = rhs->next;
            cnt++;
        }
        rhs = head;
        for (int i = 0; i < cnt - (k - 1); i++) {
            rhs = rhs->next;
        }
        auto tmp = lhs->val;
        lhs->val = rhs->val;
        rhs->val = tmp;
        return head;
    }
};


int main() {

}
