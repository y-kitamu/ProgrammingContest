/*
 * d.cpp
 *
 * Create Date : 2022-03-20 12:24:11
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>

struct Node {
    char lc;
    int lv;
    char rc;
    int rv;
    int max;
};

class SegTree {
  public:
    SegTree(std::string s) : n(s.length()) {
        offset = 1;
        while (offset < n) {
            offset *= 2;
        }
        offset--;

        nodes = std::vector<Node>((offset + 1) * 4, {' ', 0, ' ', 0, 0});
        // std::cout << "offset = " << offset << ", offset + n = " << offset + n << std::endl;
        for (int i = 0; i < n; i++) {
            update(s[i], i);
        }
    }

    int update(char c, int idx) {
        // std::cout << c << ", " << idx << std::endl;
        idx += offset;
        nodes[idx].lc = c;
        nodes[idx].lv = 1;
        nodes[idx].rc = c;
        nodes[idx].rv = 1;
        nodes[idx].max = 1;

        int max = 1;
        while (idx > 0) {
            idx = (idx - 1) / 2;
            int li = idx * 2 + 1;
            int ri = idx * 2 + 2;

            // update max
            nodes[idx].max = std::max(nodes[li].max, nodes[ri].max);
            if (nodes[li].rc == nodes[ri].lc) {
                nodes[idx].max = std::max(nodes[idx].max, nodes[li].rv + nodes[ri].lv);
            }
            // update left
            nodes[idx].lc = nodes[li].lc;
            nodes[idx].lv = nodes[li].lv;
            if (nodes[li].lv == max && nodes[li].lc == nodes[ri].lc) {
                nodes[idx].lv += nodes[ri].lv;
            }

            // update right
            nodes[idx].rc = nodes[ri].rc;
            nodes[idx].rv = nodes[ri].rv;
            if (nodes[ri].rv == max && nodes[ri].rc == nodes[li].rc) {
                nodes[idx].rv += nodes[li].rv;
            }

            // update max length
            max *= 2;
        }
        return nodes[0].max;
    }

    int n;
    int offset;
    std::vector<Node> nodes;
};

class Solution {
  public:
    std::vector<int> longestRepeating(std::string s, std::string queryCharacters,
                                      std::vector<int>& queryIndices) {
        auto seg = SegTree(s);
        int n = queryIndices.size();
        std::vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            int idx = queryIndices[i];
            char c = queryCharacters[i];
            ans[i] = seg.update(c, idx);
        }
        return ans;
    }
};


int main() {}
