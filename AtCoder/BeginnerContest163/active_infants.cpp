/*
 * active_infants.cpp
 *
 * Create Date : 2020-04-19 21:41:02
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <iostream>
#include <algorithm>
#include <vector>


int main() {
    int N;
    std::cin >> N;
    std::vector<std::pair<int, int>> A;
    for (int i = 0; i < N; i++) {
        int a;
        std::cin >> a;
        A.emplace_back(std::make_pair(i, a));
    }

    std::sort(A.begin(), A.end(),
              [](const std::pair<int, int> lhs, const std::pair<int, int> rhs)
              { return lhs.second > rhs.second; });

    long long int max = N - 1;
    long long int min = 0;
    long long int i = 0;
    long long int sum = 0;
    for (auto a = A.begin(); a != A.end(); a++, i++) {
        int diff_max = std::abs(max - a->first);
        int diff_min = std::abs(a->first - min);
        if (diff_max > diff_min) {
            sum += a->second * diff_max;
            max--;
        } else if (diff_max < diff_min) {
            sum += a->second * diff_min;
            min++;
        } else {
            auto next = a;
            next++;
            if (std::abs(max - next->first) > std::abs(next->first - min)) {
                sum += a->second * diff_min;
                min++;
            } else {
                sum += a->second * diff_max;
                max--;
            }
        }
    }
    std::cout << sum << std::endl;
}
