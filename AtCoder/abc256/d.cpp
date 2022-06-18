/**
 * @file d.cpp
 * @brief
 * @author Yusuke Kitamura <ymyk6602@gmail.com>
 * @date 2022-06-18 21:20:19
 */
#include <bits/stdc++.h>


int main() {
    int N;
    std::cin >> N;

    std::vector<int> flag(2e5 + 1, 0);
    for (int i = 0; i < N; i++) {
        int l, r;
        std::cin >> l >> r;
        flag[l]++;
        flag[r]--;
    }

    bool inner = false;
    int sum = 0;
    for (int i = 1; i <= 2e5; i++) {
        sum += flag[i];
        if (inner && sum <= 0) {
            std::cout << i << std::endl;
            inner = false;
            continue;
        }
        if (!inner && sum > 0) {
            std::cout << i << " ";
            inner = true;
        }
    }
}
