/*
 * d.cpp
 *
 * Create Date : 2022-03-20 12:24:11
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


struct Node {
    char lchar;
    int lval;
    char rchar;
    int rval;
    int max;
};


class Seg {
  public:
    Seg(std::string s) : n(s.length()) {
        offset = std::pow(2, int(log2(n)) + 1) - 1;
        std::cout << offset << ", " << n << std::endl;
        seg = std::vector<Node>(offset + n, Node{' ', 0, ' ', 0, 0});
        for (int i = 0; i < n; i++) {
            update(i, s[i]);
        }
        for (auto val : seg) {
            std::cout << val.max << " ";
        }
        std::cout << std::endl;
    }

    int update(int idx, char c) {
        std::cout << "idx = " << idx << ", char = " << c << std::endl;
        idx += offset;
        seg[idx].lval = c;
        seg[idx].rval = c;

        int max_val = 1;
        while (idx > 0) {
            idx = (idx - 1) / 2;
            int left = idx * 2 + 1;
            int right = idx * 2 + 2;
            int max = std::max(seg[left].lval, seg[right].rval);
            if (seg[left].rchar == seg[right].lchar) {
                max = std::max(max, seg[left].rval + seg[right].lval);
            }
            seg[idx].max = max;
            seg[idx].lchar = seg[left].lchar;
            seg[idx].lval = seg[left].lval;
            if (seg[left].lval == max_val && seg[left].lchar == seg[right].lchar) {
                seg[idx].lval += seg[right].lval;
            }
            seg[idx].rchar = seg[right].rchar;
            seg[idx].rval = seg[right].rval;
            if (seg[right].rval == max_val && seg[left].rchar == seg[right].rchar) {
                seg[idx].rval += seg[left].rval;
            }
            max_val *= 2;
        }
        return seg[0].max;
    }

    int n;
    int offset;
    std::vector<Node> seg;
};


class Solution {
  public:
    std::vector<int> longestRepeating(std::string s, std::string queryCharacters,
                                      std::vector<int>& queryIndices) {
        auto segtree = Seg(s);
        std::vector<int> ans(queryIndices.size());
        for (int i = 0; i < queryCharacters.length(); i++) {
            ans[i] = segtree.update(queryIndices[i], queryCharacters[i]);

            for (auto val : segtree.seg) {
                std::cout << val.max << " ";
            }
            std::cout << std::endl;
        }
        return ans;
    }
};


int main() {}
