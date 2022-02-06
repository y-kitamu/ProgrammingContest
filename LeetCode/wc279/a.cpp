/*
 * a.cpp
 */
#include <bits/stdc++.h>

class Solution {
  public:
    std::vector<int> sortEvenOdd(std::vector<int>& nums) {
        std::vector<int> odd, even;
        for (int i = 0; i < nums.size(); i++) {
            if (i % 2 == 0) {
                even.emplace_back(nums[i]);
            } else {
                odd.emplace_back(nums[i]);
            }
        }
        std::sort(even.begin(), even.end(), std::less<>());
        std::sort(odd.begin(), odd.end(), std::greater<>());

        for (int i = 0; i < nums.size(); i++) {
            if (i % 2 == 0) {
                nums[i] = even[i / 2];
            } else {
                nums[i] = odd[i / 2];
            }
        }
        return nums;
    }
};


int main() {}
