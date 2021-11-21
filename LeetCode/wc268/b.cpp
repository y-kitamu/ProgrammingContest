/*
 * b.cpp
 *
 * Create Date : 2021-11-21 11:34:23
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>

class Solution {
  public:
    int wateringPlants(std::vector<int>& plants, int capacity) {
        int cur = capacity;
        int steps = 0;
        for (int i = 0; i < plants.size(); i++) {
            if (plants[i] <= cur) {
                cur -= plants[i];
                steps++;
            } else {
                steps += i * 2 + 1;
                cur = capacity - plants[i];
            }
        }
        return steps;
    }
};


int main() {}
