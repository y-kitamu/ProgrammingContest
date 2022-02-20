/*
 * a.cpp
 *
 * Create Date : 2022-02-20 11:26:59
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


class Solution {
  public:
    int countEven(int num) {
        int ans = 0;
        for (int i = 1; i <= num; i++) {
            int num = i;
            int sum = 0;
            while (num > 0) {
                sum += num % 10;
                num /= 10;
            }
            if (sum % 2 == 0) {
                ans++;
            }
        }
        return ans;
    }
};


int main() {}
