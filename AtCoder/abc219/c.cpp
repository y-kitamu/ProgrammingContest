/*
 * c.cpp
 *
 * Create Date : 2021-09-18 21:06:47
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


std::vector<int> index_sort(std::vector<std::string>& vec) {
    std::vector<int> idx(vec.size());
    std::iota(idx.begin(), idx.end(), 0);

    std::sort(idx.begin(), idx.end(), [&vec](auto& lhs, auto& rhs) { return vec[lhs] < vec[rhs]; });
    return idx;
}


int main() {
    std::string x;
    std::cin >> x;

    std::vector<int> conv(26);
    for (int i = 0; i < 26; i++) {
        conv[(int)(x[i] - 'a')] = i;
    }

    int N;
    std::cin >> N;
    std::vector<std::string> s(N), cs(N);
    for (int i = 0; i < N; i++) {
        std::cin >> s[i];

        std::string c = "";
        for (int j = 0; j < s[i].length(); j++) {
            c += 'a' + conv[(int)(s[i][j] - 'a')];
        }
        cs[i] = c;
    }

    auto idx = index_sort(cs);
    for (auto& i : idx) {
        std::cout << s[i] << std::endl;
    }
}
