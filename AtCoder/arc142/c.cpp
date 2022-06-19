/**
 * @file c.cpp
 * @brief
 * @author Yusuke Kitamura <ymyk6602@gmail.com>
 * @date 2022-06-19 21:29:07
 */
#include <bits/stdc++.h>


int main() {
    int N;
    std::cin >> N;

    std::vector<int> l0(N), l1(N);
    for (int i = 2; i < N; i++) {
        std::cout << "? " << 1 << " " << i + 1 << std::endl;
        std::cin >> l0[i];
        std::cout << "? " << 2 << " " << i + 1 << std::endl;
        std::cin >> l1[i];
    }

    int min = N - 1;
    for (int i = 2; i < N; i++) {
        min = std::min(l0[i] + l1[i], min);
    }
    if (min != 3) {
        std::cout << "! " << min << std::endl;
        return 0;
    }
    int cnt = 0;
    for (int i = 2; i < N; i++) {
        if (min == l0[i] + l1[i]) {
            cnt++;
        }
    }
    if (cnt != min - 1) {
        std::cout << "! " << 1 << std::endl;
        return 0;
    }

    int idx0 = -1, idx1 = -1;
    for (int i = 2; i < N; i++) {
        if (l0[i] == 1 && l1[i] == 2) {
            idx0 = i;
        }
        if (l0[i] == 2 && l1[i] == 1) {
            idx1 = i;
        }
    }
    if (idx0 == -1 || idx1 == -1) {
        std::cout << "! " << 1 << std::endl;
        return 0;
    }
    int dist;
    std::cout << "? " << idx0 + 1 << " " << idx1 + 1 << std::endl;
    std::cin >> dist;
    if (dist == 1) {
        std::cout << "! " << min << std::endl;
    } else {
        std::cout << "! " << 1 << std::endl;
    }
}
