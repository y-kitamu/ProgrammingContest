/**
 * @file a.cpp
 * @brief
 * @author Yusuke Kitamura <ymyk6602@gmail.com>
 * @date 2022-05-08 20:54:05
 */
#include <bits/stdc++.h>


int main() {
    int H, W, R, C;
    std::cin >> H >> W >> R >> C;

    int ans = 4;
    if (R == 1 || R == H) {
        ans--;
    }
    if (C == 1 || C == W) {
        ans--;
    }
    if (H == 1) {
        ans--;
    }
    if (W == 1) {
        ans--;
    }
    std::cout << ans << std::endl;
}
