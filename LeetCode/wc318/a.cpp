/**
 * @file a.cpp
 * @brief
 * @author Yusuke Kitamura <ymyk6602@gmail.com>
 * @date 2022-11-06 11:28:20
 */
#include <bits/stdc++.h>

class Solution {
public:
    std::vector<int> applyOperations(std::vector<int>& nums) {
        for (int i =0 ;i < nums.size() - 1; i++) {
            if (nums[i] == nums[i + 1]) {
                nums[i] *= 2;
                nums[i + 1] = 0;
            }
        }
        std::vector<int> ans(nums.size(), 0);
        int idx = 0;
        for (auto num : nums) {
            if (num != 0) {
                ans[idx++] = num;
            }
        }
        return ans;
    }
};


int main() {

}
