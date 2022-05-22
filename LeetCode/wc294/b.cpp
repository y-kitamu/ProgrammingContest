/**
 * @file b.cpp
 * @brief
 * @author Yusuke Kitamura <ymyk6602@gmail.com>
 * @date 2022-05-22 11:31:52
 */
#include <bits/stdc++.h>

class Solution {
  public:
    int maximumBags(std::vector<int>& capacity, std::vector<int>& rocks, int additionalRocks) {
        int n = capacity.size();
        std::vector<int> diff(n);
        for (int i = 0; i < n; i++) {
            diff[i] = capacity[i] - rocks[i];
        }
        std::sort(diff.begin(), diff.end());

        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (diff[i] <= additionalRocks) {
                additionalRocks -= diff[i];
                ans++;
            }
        }
        return ans;
    }
};

int main() {}
