#include <bits/stdc++.h>


class Solution {
  public:
    int subsetXORSum(std::vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for (int i = 0; i < (1 << n); i++) {
            int res = 0;
            for (int j = 0; j < n; j++) {
                if (i & (1 << j)) {
                    res ^= nums[j];
                }
            }
            sum += res;
        }
        return sum;
    }
};

int main() {}
