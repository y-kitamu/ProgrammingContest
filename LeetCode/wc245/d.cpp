/*
 * d.cpp
 *
 * Create Date : 2021-06-13 11:58:44
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


class Solution {
  public:
    std::vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
        std::map<int, int> map;
        int flag = (1 << n) - 1;

        auto max = calc_count(flag, firstPlayer, secondPlayer, map, std::greater<int>());
        auto min = calc_count(flag, firstPlayer, secondPlayer, map, std::less<int>());
        return {min, max};
    }

    template <class Cmp>
    int calc_count(int flag, int fp, int sp, std::map<int, int>& map, Cmp compare) {
        if ((!(flag & (1 << fp)) || (!(flag & (1 << sp))))) {
            return -1;
        }
        if (map.find(flag) != map.end()) {
            return map[flag];
        }
        std::cout << flag << std::endl;
        std::vector<int> indices;
        int idx = 0;
        while ((flag >> idx) > 0) {
            if (flag & (1 << idx)) {
                indices.emplace_back(idx);
            }
            idx++;
        }
        int cnt = indices.size();
        for (int i = 0; i < cnt / 2; i++) {
            int lhs = indices[i];
            int rhs = indices[cnt - i - 1];
            if (lhs == fp && rhs == sp) {
                return 1;
            }
        }

        int val = -1;
        for (int i = 0; i < (1 << (cnt / 2)); i++) {
            int next = flag;
            for (int j = 0; j < cnt / 2; j++) {
                int lhs = indices[j], rhs = indices[cnt - j - 1];
                if (i & (1 << j)) {
                    next -= (1 << rhs);
                } else {
                    next -= (1 << lhs);
                }
            }
            int res = calc_count(next, fp, sp, map, compare);
            if (res > 0) {
                if (val == -1) {
                    val = res;
                } else if (compare(res, val)) {
                    val = res;
                }
            }
        }
        std::cout << val << std::endl;
        map[flag] = val + 1;
        return map[flag];
    }
};


int main() {}
