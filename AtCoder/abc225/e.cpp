/*
 * e.cpp
 *
 * Create Date : 2021-10-30 21:54:06
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>

struct Fraction {
    long long int x, y;
    Fraction() {}
    Fraction(int x, int y) : x(x), y(y) {}
};

bool operator>(Fraction& lhs, Fraction& rhs) { return lhs.y * rhs.x > lhs.x * rhs.y; }
bool operator<(Fraction& lhs, Fraction& rhs) { return lhs.y * rhs.x < lhs.x * rhs.y; }
bool operator==(Fraction& lhs, Fraction& rhs) { return lhs.y * rhs.x == lhs.x * rhs.y; }


std::ostream& operator<<(std::ostream& os, const Fraction& f) {
    os << f.x << ", " << f.y;
    return os;
}

int main() {
    int N;
    std::cin >> N;

    std::vector<Fraction> mins(N), maxs(N);
    for (int i = 0; i < N; i++) {
        int x, y;
        std::cin >> x >> y;
        mins[i] = Fraction(x, y - 1);
        maxs[i] = Fraction(x - 1, y);
    }

    std::vector<int> idx(N);
    std::iota(idx.begin(), idx.end(), 0);
    std::sort(idx.begin(), idx.end(), [&maxs](auto& lhs, auto& rhs) { return maxs[lhs] < maxs[rhs]; });

    int cnt = 1;
    auto cur = maxs[idx[0]];
    for (int i = 1; i < N; i++) {
        if (mins[idx[i]] < cur) {
            continue;
        }
        cnt++;
        cur = maxs[idx[i]];
    }
    std::cout << cnt << std::endl;
}
