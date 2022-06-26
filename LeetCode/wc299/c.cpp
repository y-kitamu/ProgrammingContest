/**
 * @file c.cpp
 * @brief
 * @author Yusuke Kitamura <ymyk6602@gmail.com>
 * @date 2022-06-26 11:42:22
 */
#include <bits/stdc++.h>


class Solution {
  public:
    int maximumsSplicedArray(std::vector<int>& nums1, std::vector<int>& nums2) {
        return std::max(calc(nums1, nums2), calc(nums2, nums1));
    }

    int calc(std::vector<int>& nums1, std::vector<int>& nums2) {
        int n = nums1.size();
        std::vector<int> diff_sum(n + 1, 0);
        for (int i = 0; i < n; i++) {
            diff_sum[i + 1] = diff_sum[i] + nums2[i] - nums1[i];
        }

        int max_diff = 0;
        int left = 0;
        for (int i = 1; i <= n; i++) {
            int diff = diff_sum[i] - diff_sum[left];
            max_diff = std::max(diff, max_diff);
            if (diff_sum[i] < diff_sum[left]) {
                left = i;
            }
        }

        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums1[i];
        }
        return sum + max_diff;
    }
};

int main() {}
