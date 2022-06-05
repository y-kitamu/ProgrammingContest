/**
 * @file c.cpp
 * @brief
 * @author Yusuke Kitamura <ymyk6602@gmail.com>
 * @date 2022-06-05 11:41:10
 */
#include <bits/stdc++.h>


class Solution {
  public:
    std::vector<int> arrayChange(std::vector<int>& nums, std::vector<std::vector<int>>& operations) {
        auto comp = [](auto& lhs, auto& rhs) { return lhs.second < rhs.second; };
        std::set<std::pair<int, int>, decltype(comp)> set{comp};

        for (int i = 0; i < nums.size(); i++) {
            set.insert(std::make_pair(i, nums[i]));
        }

        for (auto& ops : operations) {
            auto val = set.find(std::make_pair(-1, ops[0]));
            auto idx = val->first;
            set.erase(val);
            set.insert(std::make_pair(idx, ops[1]));
        }

        std::vector<int> ans(nums.size());
        for (auto& pair : set) {
            ans[pair.first] = pair.second;
        }

        return ans;
    }
};

int main() {}
