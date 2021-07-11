/*
 * d.cpp
 *
 * Create Date : 2021-07-11 12:22:00
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
    TreeNode *canMerge(std::vector<TreeNode *> &trees) {
        std::vector<TreeNode *> nodes(5 * 1e4, nullptr);

        if (!createTree(nodes, trees)) {
            return nullptr;
        }

        if (validTree()) {
            return nullptr;
        }
        return nullptr;
    }

    bool createTree(std::vector<TreeNode *> &nodes, std::vector<TreeNode *> &trees) {
        std::vector<int> parents(nodes.size());
        std::iota(nodes.begin(), nodes.end(), 0);

        auto registering = [&nodes](TreeNode *node) {
            if (nodes[node->val] == nullptr) {
                nodes[node->val] = node;
                return;
            }
        };

        for (auto &tree : trees) {
            registering(tree);
            if (tree->left != nullptr) {
                registering(tree->left);
            }
            if (tree->right != nullptr) {
                registering(tree->right);
            }
        }

        int cnt = 0;
        for (int i = 0; i < parents.size(); i++) {
            if (i == parents[i]) {
                cnt++;
            }
        }
        return cnt == 1;
    }

    bool validTree() {}
};


int main() {}
