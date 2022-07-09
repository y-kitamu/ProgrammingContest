/**
 * @file e.cpp
 * @brief
 * @author Yusuke Kitamura <ymyk6602@gmail.com>
 * @date 2022-07-09 21:50:25
 */
#include <bits/stdc++.h>


int main() {
    int N;
    std::cin >> N;

    std::map<int, std::vector<int>> map;
    std::vector<std::map<int, int>> maps(N);
    for (int i = 0; i < N; i++) {
        int m;
        std::cin >> m;

        for (int j = 0; j < m; j++) {
            int p, e;
            std::cin >> p >> e;
            maps[i][p] = e;
            map[p].emplace_back(e);
        }
    }
    for (auto& pair : map) {
        std::sort(pair.second.begin(), pair.second.end(), std::greater<int>());
    }

    int cnt = 0;
    for (int i = 0; i < N; i++) {
        for (auto& [idx, val] : maps[i]) {
            if (map[idx].size() == 1) {
                cnt++;
                break;
            }
            if (map[idx][0] == val && map[idx][1] != val) {
                cnt++;
                break;
            }
        }
    }
    if (cnt < N) {
        cnt++;
    }

    std::cout << cnt << std::endl;
}
