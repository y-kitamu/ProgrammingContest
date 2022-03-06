/*
 * c.cpp
 *
 * Create Date : 2022-03-06 11:57:24
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


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
    TreeNode *createBinaryTree(std::vector<std::vector<int>> &descriptions) {
        std::map<int, std::vector<std::pair<int, int>>> ll;
        std::vector<int> root(2 * 1e5, -1);

        auto find_root = [&root](auto &idx) {
            std::vector<int> update;
            while (root[idx] != idx) {
                update.emplace_back(idx);
                idx = root[idx];
            }
            for (auto &val : update) {
                root[val] = idx;
            }
            return idx;
        };

        for (auto &desc : descriptions) {
            ll[desc[0]].emplace_back(std::make_pair(desc[1], desc[2]));

            if (root[desc[0]] == -1) {
                root[desc[0]] = desc[0];
            }
            int r = find_root(desc[0]);
            root[desc[1]] = r;
        }
        int ridx = 0;
        for (; ridx < root.size(); ridx++) {
            if (root[ridx] == ridx) {
                break;
            }
        }
        TreeNode *rn = new TreeNode(ridx);
        dfs(rn, ll);
        return rn;
    }

    void dfs(TreeNode *rn, std::map<int, std::vector<std::pair<int, int>>> &ll) {
        for (auto &val : ll[rn->val]) {
            TreeNode *node = new TreeNode(val.first);
            dfs(node, ll);
            if (val.second == 1) {
                rn->left = node;
            } else {
                rn->right = node;
            }
        }
    }
};


int main() {}
