/*
 * c.cpp
 *
 * Create Date : 2021-09-19 11:52:58
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>

class DetectSquares {
  public:
    DetectSquares() {}

    void add(std::vector<int> point) { map[point[1]][point[0]]++; }

    int count(std::vector<int> point) {
        long long int sum = 0;
        for (int i = 0; i <= 1000; i++) {
            if (i == point[0]) {
                continue;
            }
            int x0 = i;
            int dist = std::abs(point[0] - i);
            int yp = point[1] + dist, yn = point[1] - dist;

            if (yp <= 1000) {
                sum += map[yp][point[0]] * map[yp][x0] * map[point[1]][x0];
            }
            if (yn >= 0) {
                sum += map[yn][point[0]] * map[yn][x0] * map[point[1]][x0];
            }
        }
        return sum;
    }

    std::vector<std::vector<long long int>> map =
        std::vector<std::vector<long long int>>(1001, std::vector<long long int>(1001, 0));
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */


int main() {}
