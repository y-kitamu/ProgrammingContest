/**
 * @file b.cpp
 * @brief
 * @author Yusuke Kitamura <ymyk6602@gmail.com>
 * @date 2022-06-05 11:35:10
 */
#include <bits/stdc++.h>

class Solution {
  public:
    int partitionArray(std::vector<int>& nums, int k) {
        std::sort(nums.begin(), nums.end());
        int cnt = 1;
        int cur = nums[0];
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] - cur > k) {
                cnt++;
                cur = nums[i];
            }
        }
        return cnt;
    }
};

int main() {}
