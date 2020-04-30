/*
 * integer_casrds.cpp
 *
 * Create Date : 2020-04-25 16:43:35
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <iostream>
#include <algorithm>
#include <vector>


int main() {
    int N, M;
    std::cin >> N >> M;

    std::vector<int> A(N);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }
    std::sort(A.begin(), A.end(), [](auto lhs, auto rhs) {return lhs < rhs;});

    std::vector<std::pair<int, int>> re(M, std::pair<int, int>());
    for (int i = 0; i < M; i++) {
        std::cin >> re[i].first >> re[i].second;
    }

    std::sort(re.begin(), re.end(), [](auto lhs, auto rhs) {return lhs.second > rhs.second;});

    long long int s = 0;
    int re_idx = 0;
    for (int i = 0; i < N; i++) {
        int val = A[i];
        if (re_idx < M && re[re_idx].second > val) {
            val = re[re_idx].second;
            re[re_idx].first--;
            if (re[re_idx].first == 0) {
                re_idx++;
            }
        }
        s += static_cast<long long int>(val);
    }
    std::cout << s << std::endl;
}
