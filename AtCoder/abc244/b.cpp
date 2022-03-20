/*
 * b.cpp
 *
 * Create Date : 2022-03-20 21:00:58
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    int N;
    std::string T;
    std::cin >> N >> T;

    int x = 0, y = 0;
    char dir = 'W';
    for (int i = 0; i < N; i++) {
        if (T[i] == 'S') {
            if (dir == 'W') {
                x++;
            } else if (dir == 'S') {
                y--;
            } else if (dir == 'E') {
                x--;
            } else if (dir == 'N') {
                y++;
            }
        } else {
            if (dir == 'W') {
                dir = 'S';
            } else if (dir == 'S') {
                dir = 'E';
            } else if (dir == 'E') {
                dir = 'N';
            } else if (dir == 'N') {
                dir = 'W';
            }
        }
    }
    std::cout << x << " " << y << std::endl;
}
