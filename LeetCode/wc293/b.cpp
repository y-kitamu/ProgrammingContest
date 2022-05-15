/**
 * @file b.cpp
 * @brief
 * @author Yusuke Kitamura <ymyk6602@gmail.com>
 * @date 2022-05-15 11:38:47
 */
#include <bits/stdc++.h>

class Solution {
  public:
    int maxConsecutive(int bottom, int top, std::vector<int>& special) {
        std::sort(special.begin(), special.end());
        int maxi = std::max(special[0] - bottom, top - special[special.size() - 1]);
        for (int i = 1; i < special.size(); i++) {
            maxi = std::max(maxi, special[i] - special[i - 1] - 1);
        }
        return maxi;
    }
};


int main() {}
