/**
 * @file d.cpp
 * @brief
 * @author Yusuke Kitamura <ymyk6602@gmail.com>
 * @date 2022-07-17 21:26:09
 */
#include <bits/stdc++.h>


int main() {
    int N, K;
    std::cin >> N >> K;

    std::vector<int> P(N);
    for (int i = 0; i < N; i++) {
        std::cin >> P[i];
    }

    std::vector<int> ans(N, -1);
    std::vector<int> root(N + 1, -1);
    std::map<int, std::vector<int>> cnts;
    std::set<int> field;

    for (int i = 0; i < N; i++) {
        auto itr = field.lower_bound(P[i]);
        if (itr == field.end()) {
            root[P[i]] = P[i];
            field.insert(P[i]);
        } else {
            root[P[i]] = root[*itr];
            field.erase(itr);
            field.insert(P[i]);
        }
        cnts[root[P[i]]].emplace_back(P[i]);
        if (cnts[root[P[i]]].size() == K) {
            for (auto j : cnts[root[P[i]]]) {
                ans[j - 1] = i + 1;
            }
            field.erase(P[i]);
        }
        // for (auto& i : field) {
        //     std::cout << i << " ";
        // }
        // std::cout << std::endl;
    }

    for (auto i : ans) {
        std::cout << i << std::endl;
    }
}
