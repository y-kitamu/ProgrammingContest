/*
 * d.cpp
 *
 * Create Date : 2021-11-07 21:15:53
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>

long long int LCM(long long int a, long long int b) {
    while (b != 0) {
        long long int tmp = a;
        a = b;
        b = tmp % b;
    }
    return a;
}


int main() {
    int N;
    std::cin >> N;

    std::vector<long long int> x(N), y(N);
    for (int i = 0; i < N; i++) {
        std::cin >> x[i] >> y[i];
    }

    std::set<std::pair<int, int>> set;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            long long int dx = x[j] - x[i];
            long long int dy = y[j] - y[i];
            if (dx == 0) {
                dy = 1;
            }
            if (dy == 0) {
                dx = 1;
            }
            if (dx != 0 && dy != 0) {
                long long int lcm = LCM(dx, dy);
                dx /= lcm;
                dy /= lcm;
            }
            set.insert(std::make_pair(dx, dy));
            set.insert(std::make_pair(-dx, -dy));
        }
    }
    std::cout << set.size() << std::endl;
}
