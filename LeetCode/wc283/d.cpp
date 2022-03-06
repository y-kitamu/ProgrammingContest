/*
 * d.cpp
 *
 * Create Date : 2022-03-06 12:15:32
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>

class Solution {
  public:
    std::vector<int> replaceNonCoprimes(std::vector<int>& nums) {
        while (true) {
            std::vector<int> ans;
            bool flag = true;
            int idx = 0;
            while (idx < nums.size()) {
                int val = nums[idx];
                int i = idx + 1;
                int ai = ans.size() - 1;
                while (true) {
                    if (i < nums.size() && gcd(val, nums[i]) != 1) {
                        int g = gcd(val, nums[i]);
                        flag = false;
                        val = val / g * nums[i];
                        i++;
                    } else if (ai >= 0) {
                        int ag = gcd(ans[ai], val);
                        if (ag != 1) {
                            flag = false;
                            val = val / ag * ans[ai];
                            ans.pop_back();
                            ai--;
                        } else {
                            break;
                        }
                    } else {
                        break;
                    }
                }
                ans.emplace_back(val);
                idx = i;
            }
            nums = ans;
            if (flag) {
                return nums;
            }
        }
    }

    int gcd(int a, int b) {
        while (b > 0) {
            auto tmp = b;
            b = a % b;
            a = tmp;
        }
        return a;
    }
};

int main() {}
