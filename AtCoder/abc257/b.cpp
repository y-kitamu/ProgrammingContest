/**
 * @file b.cpp
 * @brief
 * @author Yusuke Kitamura <ymyk6602@gmail.com>
 * @date 2022-06-25 21:02:29
 */
#include <bits/stdc++.h>

int main() {
    int N, K, Q;
    std::cin >> N >> K >> Q;

    std::vector<int> map(N + 1, 0);
    for (int i = 0; i < K; i++) {
        int a;
        std::cin >> a;
        map[a] = 1;
    }
    for (int q = 0; q < Q; q++) {
        int l;
        std::cin >> l;

        int cnt = 0;
        for (int i = 0; i < map.size(); i++) {
            if (map[i] == 1) {
                cnt++;
            }
            if (cnt == l) {
                if (i + 1 < map.size() && map[i + 1] == 0) {
                    map[i + 1] = 1;
                    map[i] = 0;
                }
                break;
            }
        }
    }
    std::vector<int> ans;
    for (int i = 0; i < map.size(); i++) {
        if (map[i] == 1) {
            ans.emplace_back(i);
        }
    }
    for (int i = 0; i < ans.size(); i++) {
        std::cout << ans[i];
        if (i < ans.size() - 1) {
            std::cout << " ";
        }
    }
    std::cout << std::endl;
}
