/**
 * @file b.cpp
 * @brief
 * @author Yusuke Kitamura <ymyk6602@gmail.com>
 * @date 2022-05-01 11:36:08
 */
#include <bits/stdc++.h>

class Solution {
  public:
    int minimumCardPickup(std::vector<int>& cards) {
        std::map<int, int> idxs;
        int ans = -1;
        for (int i = 0; i < cards.size(); i++) {
            if (idxs.find(cards[i]) != idxs.end()) {
                int val = i - idxs[cards[i]] + 1;
                if (ans == -1) {
                    ans = val;
                } else {
                    ans = std::min(ans, val);
                }
            }
            idxs[cards[i]] = i;
        }
        return ans;
    }
};

int main() {}
