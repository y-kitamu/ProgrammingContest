#include <bits/stdc++.h>

class Solution {
  public:
    int maxAscendingSum(std::vector<int>& nums) {
        int max = 0;
        int sum = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i - 1] < nums[i]) {
                sum += nums[i];
            } else {
                max = std::max(sum, max);
                sum = nums[i];
            }
        }
        return std::max(sum, max);
    }
};


int main() {}
