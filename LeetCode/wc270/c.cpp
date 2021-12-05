/*
 * c.cpp
 *
 * Create Date : 2021-12-05 11:57:14
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>

// Definition for a binary tree node.
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
    std::string getDirections(TreeNode *root, int startValue, int destValue) {
        std::vector<std::vector<char>> strs(2);
        dfs(root, startValue, destValue, strs);
        std::string ans = "";
        for (auto &c : strs[0]) {
            ans += c;
        }
        int n = strs[1].size();
        for (int i = 0; i < n; i++) {
            ans += strs[1][n - i - 1];
        }
        return ans;
    }

    int dfs(TreeNode *node, int &sval, int &dval, std::vector<std::vector<char>> &str) {
        int ret = 0;
        if (node->left != nullptr) {
            auto res = dfs(node->left, sval, dval, str);
            if (res == 3) {
                return res;
            }
            if (res == 1) {
                str[0].emplace_back('U');
            }
            if (res == 2) {
                str[1].emplace_back('L');
            }
            ret += res;
        }
        if (node->right != nullptr) {
            auto res = dfs(node->right, sval, dval, str);
            if (res == 3) {
                return res;
            }
            if (res == 1) {
                str[0].emplace_back('U');
            }
            if (res == 2) {
                str[1].emplace_back('R');
            }
            ret += res;
        }

        if (node->val == sval) {
            ret += 1;
        }
        if (node->val == dval) {
            ret += 2;
        }
        return ret;
    }
};

int main() {}
