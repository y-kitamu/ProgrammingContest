/*
 * b.cpp
 *
 * Create Date : 2021-09-12 11:33:13
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>

class Solution {
  public:
    long long interchangeableRectangles(std::vector<std::vector<int>>& rectangles) {
        for (auto& rect : rectangles) {
            int g = gcd(rect[0], rect[1]);
            rect[0] /= g;
            rect[1] /= g;
        }
        std::sort(rectangles.begin(), rectangles.end(), [](auto& lhs, auto& rhs) {
            if (lhs[0] == rhs[0]) {
                return lhs[1] < rhs[1];
            }
            return lhs[0] < rhs[0];
        });

        long long int sum = 0;
        long long int c = 1;
        for (int i = 1; i < rectangles.size(); i++) {
            auto prev = rectangles[i - 1];
            auto cur = rectangles[i];
            if (prev[0] == cur[0] && prev[1] == cur[1]) {
                c++;
            } else {
                sum += c * (c - 1) / 2;
                c = 1;
            }
        }
        sum += c * (c - 1) / 2;
        return sum;
    }

    int gcd(int a, int b) {
        while (b > 0) {
            int tmp = b;
            b = a % b;
            a = tmp;
        }
        return a;
    }
};


int main() {}
