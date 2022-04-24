/**
 * @file c.cpp
 * @brief
 * @author Yusuke Kitamura <ymyk6602@gmail.com>
 * @date 2022-04-24 21:30:38
 */
#include <bits/stdc++.h>


int main() {
    int N, M;
    std::cin >> N >> M;
    bool swap = false;
    if (N < M) {
        swap = true;
        std::swap(N, M);
    }

    std::vector<std::vector<int>> ans;
    std::set<int> x3y;
    for (int i = 4; i <= 3 * N + M; i++) {
        int ny = std::min((i - 1) / 3 - (i - 9) / 20, M);
        // int ny = std::min((i - 1) / 3, M);
        int nx = i - ny * 3;
        if (nx > N) {
            continue;
        }
        while (ny > 0 && nx <= N && x3y.find(nx * 3 + ny) != x3y.end()) {
            ny--;
            nx += 3;
        }

        if (1 <= nx && nx <= N && 1 <= ny && ny <= M) {
            ans.emplace_back(std::vector<int>{nx, ny});
            x3y.insert(nx * 3 + ny);
        }
    }

    std::cout << ans.size() << std::endl;
    for (auto& vec : ans) {
        if (swap) {
            std::cout << vec[1] << " " << vec[0] << std::endl;
        } else {
            std::cout << vec[0] << " " << vec[1] << std::endl;
        }
    }
}
