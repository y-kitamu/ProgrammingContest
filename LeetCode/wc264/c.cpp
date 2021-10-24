/*
 * c.cpp
 *
 * Create Date : 2021-10-24 12:17:35
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>

class Solution {
  public:
    struct Node {
        int idx;
        int p;
        std::vector<int> cs;
        std::vector<long long int> cnts;
    };

    int countHighestScoreNodes(std::vector<int>& parents) {
        int n = parents.size();
        std::vector<Node> nodes(n, Node{0, 0, {}, {}});
        for (int i = 0; i < n; i++) {
            nodes[i].idx = i;
            nodes[i].p = parents[i];
            if (parents[i] >= 0) {
                nodes[parents[i]].cs.emplace_back(i);
            }
        }
        dfs(0, nodes);
        long long int sum = 0;
        std::map<long long int, int> cnts;
        for (int i = 0; i < n; i++) {
            long long int res = n - 1;
            long long int val = 1;
            for (auto& c : nodes[i].cnts) {
                val *= c;
                res -= c;
            }
            if (res > 0) {
                val *= res;
            }
            if (cnts.find(val) == cnts.end()) {
                cnts[val] = 0;
            }
            cnts[val]++;
            sum = std::max(sum, val);
        }
        return cnts[sum];
    }

    int dfs(int idx, std::vector<Node>& nodes) {
        for (auto& next : nodes[idx].cs) {
            nodes[idx].cnts.emplace_back(dfs(next, nodes));
        }
        int cnts = 1;
        for (auto& val : nodes[idx].cnts) {
            cnts += val;
        }
        return cnts;
    }
};

int main() {}
