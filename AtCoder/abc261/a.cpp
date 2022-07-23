/**
 * @file a.cpp
 * @brief
 * @author Yusuke Kitamura <ymyk6602@gmail.com>
 * @date 2022-07-23 20:58:23
 */
#include <bits/stdc++.h>


int main() {
    int L1, R1, L2, R2;
    std::cin >> L1 >> R1 >> L2 >> R2;

    int cnt = 0;
    for (int i = 0; i <= 100; i++) {
        if (L1 <= i && i <= R1 && L2 <= i && i <= R2) {
            cnt++;
        }
    }
    if (cnt > 0) {
        cnt--;
    }
    std::cout << cnt << std::endl;
}
