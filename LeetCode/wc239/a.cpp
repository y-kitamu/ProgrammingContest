#include <bits/stdc++.h>


class Solution {
  public:
    int getMinDistance(std::vector<int>& nums, int target, int start) {
        for (int i = 0; i < nums.size(); i++) {
            if (start - i >= 0 && nums[start - i] == target) {
                return i;
            }
            if (start + i < nums.size() && nums[start + i] == target) {
                return i;
            }
        }
        return nums.size();
    }
};


int main() {}
