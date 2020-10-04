#include <bits/stdc++.h>

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        std::vector<TreeNode*> init_que = {root};
        return check(0, init_que);
    }

    bool check(int level, std::vector<TreeNode*> que) {
        std::vector<TreeNode*> next_que;

        int before_val = 0;
        if (level % 2 == 1) {
            before_val = 2e6;
        }
        for (auto q : que) {
            if ((q->val + level) % 2 == 0) {
                return false;
            }
            if (level % 2 == 0 && q->val <= before_val) {
                return false;
            }
            if (level % 2 == 1 && q->val >= before_val) {
                return false;
            }
            before_val = q->val;
            if (q->left != nullptr) {
                next_que.emplace_back(q->left);
            }
            if (q->right != nullptr) {
                next_que.emplace_back(q->right);
            }
        }
        if (next_que.empty()) {
            return true;
        }
        return check(level + 1, next_que);
    }
};


int main() {
    return 0;
}
