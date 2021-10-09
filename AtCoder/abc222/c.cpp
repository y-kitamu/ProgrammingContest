/*
 * c.cpp
 *
 * Create Date : 2021-10-09 21:03:39
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


int main() {
    int N, M;

    std::cin >> N >> M;

    std::vector<std::vector<char>> a(2 * N, std::vector<char>(M));
    for (int i = 0; i < 2 * N; i++) {
        for (int j = 0; j < M; j++) {
            std::cin >> a[i][j];
        }
    }

    std::vector<int> val(2 * N, 0);

    auto index_sort = [&val, &N]() {
        std::vector<int> order(2 * N);
        std::iota(order.begin(), order.end(), 0);
        std::sort(order.begin(), order.end(), [&val](auto& lhs, auto& rhs) {
            if (val[lhs] == val[rhs]) {
                return lhs < rhs;
            }
            return val[lhs] > val[rhs];
        });
        return order;
    };
    for (int i = 0; i < M; i++) {
        auto idx = index_sort();
        for (int j = 0; j < N; j++) {
            auto lhs = a[idx[j * 2]][i];
            auto rhs = a[idx[j * 2 + 1]][i];
            if (lhs == rhs) {
            } else if (lhs == 'G') {
                if (rhs == 'C') {
                    val[idx[j * 2]]++;
                } else {
                    val[idx[j * 2 + 1]]++;
                }
            } else if (lhs == 'C') {
                if (rhs == 'P') {
                    val[idx[j * 2]]++;
                } else {
                    val[idx[j * 2 + 1]]++;
                }
            } else if (lhs == 'P') {
                if (rhs == 'G') {
                    val[idx[j * 2]]++;
                } else {
                    val[idx[j * 2 + 1]]++;
                }
            }
        }
    }

    auto idx = index_sort();
    for (auto& i : idx) {
        std::cout << i + 1 << std::endl;
    }
}
