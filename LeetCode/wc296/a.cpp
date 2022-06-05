/**
 * @file a.cpp
 * @brief
 * @author Yusuke Kitamura <ymyk6602@gmail.com>
 * @date 2022-06-05 11:30:07
 */
#include <bits/stdc++.h>

class Solution {
  public:
    int minMaxGame(std::vector<int>& nums) { return replace(nums)[0]; }

    std::vector<int> replace(std::vector<int>& nums) {
        if (nums.size() == 1) {
            return nums;
        }
        std::vector<int> arr(nums.size() / 2);
        for (int i = 0; i < arr.size(); i++) {
            if (i % 2 == 0) {
                arr[i] = std::min(nums[2 * i], nums[2 * i + 1]);
            } else {
                arr[i] = std::max(nums[2 * i], nums[2 * i + 1]);
            }
        }
        return replace(arr);
    }
};
