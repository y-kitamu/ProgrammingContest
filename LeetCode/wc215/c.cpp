#include <bits/stdc++.h>

class Solution {
public:
    int minOperations(std::vector<int>& nums, int x) {
        int left = 0, right = nums.size() - 1;

        int sum = 0;
        for (auto val : nums) {
            sum += val;
        }

        int length = nums.size();
        int minimum = nums.size() + 1;
        for (int left = 0; left < length; left++) {
            int val = x - sum;
            if (val == 0) {
                minimum = length;
                break;
            }
            for (int right = left; right < length; right++) {
                val += nums[right];
                if (val == 0) {
                    minimum = std::min(minimum, length - (right - left + 1));
                    break;
                }
            }
        }
        if (minimum > nums.size()) {
            return -1;
        }
        return minimum;
    }
};


int main() {
}
