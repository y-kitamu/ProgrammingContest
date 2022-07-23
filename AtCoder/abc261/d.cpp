/**
 * @file d.cpp
 * @brief
 * @author Yusuke Kitamura <ymyk6602@gmail.com>
 * @date 2022-07-23 21:11:23
 */
#include <bits/stdc++.h>


int main() {
    int N, M;
    std::cin >> N >> M;

    std::vector<long long int> X(N);
    for (int i = 0; i < N; i++) {
        std::cin >> X[i];
    }

    std::vector<std::vector<long long int>> bonus(M, std::vector<long long int>(2));
    for (int i = 0; i < M; i++) {
        std::cin >> bonus[i][0] >> bonus[i][1];
    }
    std::sort(bonus.begin(), bonus.end(), [](auto& lhs, auto& rhs) { return lhs[0] < rhs[0]; });

    std::vector<long long int> count(N + 1, 0);

    for (int i = 0; i < N; i++) {
        std::vector<long long int> new_count(N + 1, 0);
        for (int j = 0; j <= i; j++) {
            new_count[j + 1] = count[j] + X[i];
            auto itr = std::lower_bound(bonus.begin(), bonus.end(), j + 1,
                                        [](auto& lhs, auto& rhs) { return lhs[0] < rhs; });
            if (itr != bonus.end() && (*itr)[0] == j + 1) {
                new_count[j + 1] += (*itr)[1];
            }
            new_count[0] = std::max(new_count[0], count[j]);
        }
        count = new_count;
        // for (auto& val : count) {
        //     std::cout << val << " ";
        // }
        // std::cout << std::endl;
    }

    long long int ans = 0;
    for (auto& val : count) {
        ans = std::max(val, ans);
    }
    std::cout << ans << std::endl;
}
