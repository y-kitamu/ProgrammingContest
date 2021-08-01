/*
 * b.cpp
 *
 * Create Date : 2021-08-01 11:35:36
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>

class Solution {
  public:
    long long numberOfWeeks(std::vector<int>& milestones) {
        std::sort(milestones.begin(), milestones.end());

        long long int sum = 0;
        for (int i = 0; i < milestones.size() - 1; i++) {
            sum += milestones[i];
        }

        sum += std::min((long long int)milestones[milestones.size() - 1], sum + 1);
        return sum;
    }
};

int main() {}
