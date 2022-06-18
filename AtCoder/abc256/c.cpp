/**
 * @file c.cpp
 * @brief
 * @author Yusuke Kitamura <ymyk6602@gmail.com>
 * @date 2022-06-18 21:05:28
 */
#include <bits/stdc++.h>

std::vector<std::vector<int>> pairs(int val) {
    std::vector<std::vector<int>> res;
    for (int i11 = 1; i11 < val; i11++) {
        for (int i12 = 1; i12 < val - i11; i12++) {
            res.emplace_back(std::vector<int>{i11, i12, val - i11 - i12});
        }
    }
    return res;
}

int main() {
    int h1, h2, h3, w1, w2, w3;
    std::cin >> h1 >> h2 >> h3 >> w1 >> w2 >> w3;

    auto v1s = pairs(h1);
    auto v2s = pairs(h2);

    int cnt = 0;
    for (auto v1 : v1s) {
        for (auto v2 : v2s) {
            auto i31 = w1 - (v1[0] + v2[0]);
            auto i32 = w2 - (v1[1] + v2[1]);
            auto i33 = w3 - (v1[2] + v2[2]);
            if (i31 < 1 || i32 < 1 || i33 < 1) {
                continue;
            }
            if (i31 + i32 + i33 == h3) {
                cnt++;
            }
        }
    }
    std::cout << cnt << std::endl;
}
