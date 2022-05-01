/**
 * @file c.cpp
 * @brief
 * @author Yusuke Kitamura <ymyk6602@gmail.com>
 * @date 2022-05-01 11:42:20
 */
#include <bits/stdc++.h>

class Solution {
  public:
    int countDistinct(std::vector<int>& nums, int k, int p) {
        int ans = 0;
        auto cmp = [](auto& lhs, auto& rhs) {
            if (lhs.size() == rhs.size()) {
                for (int i = 0; i < lhs.size(); i++) {
                    if (lhs[i] == rhs[i]) {
                        continue;
                    }
                    return lhs[i] < rhs[i];
                }
                return false;
            }
            return lhs.size() < rhs.size();
        };

        std::set<std::vector<int>, decltype(cmp)> set{cmp};
        for (int left = 0; left < nums.size(); left++) {
            for (int right = left + 1; right <= nums.size(); right++) {
                int cnt = 0;
                for (int i = left; i < right; i++) {
                    if (nums[i] % p == 0) {
                        cnt++;
                    }
                }
                std::vector<int> sub(nums.begin() + left, nums.begin() + right);
                if (set.find(sub) == set.end() && cnt <= k) {
                    set.insert(sub);
                    ans++;
                }
            }
        }
        return ans;
    }
};

int main() {}
