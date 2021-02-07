#include <bits/stdc++.h>


class Solution {
  public:
    bool check(std::vector<int>& nums) {
        int n = nums.size();
        int left_idx = 0;
        for (; left_idx < n - 1; left_idx++) {
            if (nums[left_idx] > nums[left_idx + 1]) {
                break;
            }
        }

        int right_idx = n;
        for (; right_idx > 0; right_idx--) {
            if (nums[right_idx - 1] > nums[right_idx % n]) {
                break;
            }
        }

        return (left_idx + n - right_idx + 1 >= n);
    }
};

int main() {}
