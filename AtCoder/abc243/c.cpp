/*
 * c.cpp
 *
 * Create Date : 2022-03-12 21:05:02
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


struct Person {
    int val;
    char dir;
    Person(int val, char dir) : val(val), dir(dir) {}
};


int main() {
    int N;
    std::cin >> N;

    std::vector<int> X(N), Y(N);
    for (int i = 0; i < N; i++) {
        std::cin >> X[i] >> Y[i];
    }
    std::string S;
    std::cin >> S;

    std::map<int, std::vector<Person>> map;

    for (int i = 0; i < N; i++) {
        map[Y[i]].emplace_back(Person(X[i], S[i]));
    }

    for (auto& pair : map) {
        if (pair.second.size() == 1) {
            continue;
        }

        auto ps = pair.second;
        std::sort(ps.begin(), ps.end(), [](auto& lhs, auto& rhs) { return lhs.val < rhs.val; });

        bool is_right = false;
        for (auto& p : ps) {
            if (is_right && p.dir == 'L') {
                std::cout << "Yes" << std::endl;
                return 0;
            }
            if (p.dir == 'R') {
                is_right = true;
            }
        }
    }
    std::cout << "No" << std::endl;
}
