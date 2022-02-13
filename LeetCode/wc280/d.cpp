/*
 * d.cpp
 *
 * Create Date : 2022-02-13 12:11:09
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


class Solution {
  public:
    int maximumANDSum(std::vector<int>& nums, int numSlots) {
        std::sort(nums.begin(), nums.end(), std::greater<>());

        std::vector<int> flag(nums.size(), 0);
        std::vector<int> cnts(numSlots + 1, 0);
        int sum = 0;
        for (int i = 0; i < 4; i++) {
            for (int j = 3; j >= i; j--) {
                for (int n = 0; n < nums.size(); n++) {
                    if (flag[n] == 1 || !((nums[n] >> (3 - i)) & 1)) {
                        continue;
                    }
                    for (int l = 1; l <= numSlots; l++) {
                        if (cnts[l] == 2) {
                            continue;
                        }
                        bool match = true;
                        for (int k = i; k <= j; k++) {
                            if (1 & ((nums[n] >> (3 - k)) ^ (l >> (3 - k)))) {
                                match = false;
                                break;
                            }
                        }
                        if (match) {
                            std::cout << i << ", " << j << ", " << nums[n] << ", " << l << std::endl;
                            sum += nums[n] & l;
                            flag[n] = 1;
                            cnts[l]++;
                            break;
                        }
                        std::cout << nums[n] << " , " << l << std::endl;
                    }
                }
            }
        }
        return sum;
    }
};


int main() {}
