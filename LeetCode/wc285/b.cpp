/*
 * b.cpp
 *
 * Create Date : 2022-03-20 11:39:12
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>

class Solution {
  public:
    int countCollisions(std::string directions) {
        std::deque<char> que;

        int cnt = 0;
        for (int i = 0; i < directions.length(); i++) {
            char c = directions[i];
            while (!que.empty()) {
                char b = que.back();
                if (b == 'R' && c == 'S') {
                    que.pop_back();
                    c = 'S';
                    cnt++;
                } else if (b == 'R' && c == 'L') {
                    que.pop_back();
                    c = 'S';
                    cnt += 2;
                } else if (b == 'S' && c == 'L') {
                    c = 'S';
                    cnt++;
                } else {
                    break;
                }
            }
            que.push_back(c);
        }
        return cnt;
    }
};


int main() {}
