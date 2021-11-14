/*
 * a.cpp
 *
 * Create Date : 2021-11-14 11:28:49
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>

class Solution {
  public:
    int timeRequiredToBuy(std::vector<int>& tickets, int k) {
        int time = 0;
        int n = tickets.size();
        while (true) {
            for (int i = 0; i < n; i++) {
                if (tickets[i] == 0) {
                    continue;
                }
                tickets[i]--;
                time++;
                if (tickets[i] == 0 && i == k) {
                    return time;
                }
            }
        }
        return time;
    }
};

int main() {}
