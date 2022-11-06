/**
 * @file b.cpp
 * @brief
 * @author Yusuke Kitamura <ymyk6602@gmail.com>
 * @date 2022-11-06 11:34:03
 */
#include <bits/stdc++.h>


class Solution {
  public:
    long long maximumSubarraySum(std::vector<int>& nums, int k) {
        long long sum = 0;
        std::map<int, int> cnts;
        std::set<int> vals;
        for (int i = 0; i < k; i++) {
            sum += nums[i];
            cnts[nums[i]]++;
            vals.insert(nums[i]);
        }
        long long max_sum = vals.size() == k ? sum : 0;
        for (int i = k; i < nums.size(); i++) {
            sum += nums[i] - nums[i - k];
            cnts[nums[i - k]]--;
            cnts[nums[i]]++;
            if (cnts[nums[i - k]] == 0) {
                vals.erase(nums[i - k]);
            }
            vals.insert(nums[i]);
            if (vals.size() == k) {
                max_sum = std::max(max_sum, sum);
            }
        }
        return max_sum;
    }
};

int main() {}
