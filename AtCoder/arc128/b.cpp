/*
 * b.cpp
 *
 * Create Date : 2021-10-16 21:19:24
 * Copyright (c) 2019- Yusuke Kitamura <ymyk6602@gmail.com>
 */
#include <bits/stdc++.h>


long long int solve(long long int R, long long int G, long long int B) {
    if (R > G || (G - R) % 3 != 0) {
        return -1;
    }
    // if (G - R > 3 * (B + 2 * R)) {
    //     return -1;
    // }
    return G;
}


int main() {
    int T;
    std::cin >> T;

    for (int i = 0; i < T; i++) {
        long long int R, G, B;
        std::cin >> R >> G >> B;

        long long int rgb = solve(R, G, B);
        long long int rbg = solve(R, B, G);
        long long int gbr = solve(G, B, R);
        long long int grb = solve(G, R, B);
        long long int brg = solve(B, R, G);
        long long int bgr = solve(B, G, R);
        if (rgb == -1 && rbg == -1 && gbr == -1 && grb == -1 && brg == -1 && bgr == -1) {
            std::cout << -1 << std::endl;
        } else {
            long long int ans = 1e18;
            if (rgb != -1) {
                ans = std::min(ans, rgb);
            }
            if (rbg != -1) {
                ans = std::min(ans, rbg);
            }
            if (gbr != -1) {
                ans = std::min(ans, gbr);
            }
            if (grb != -1) {
                ans = std::min(ans, grb);
            }
            if (brg != -1) {
                ans = std::min(ans, brg);
            }
            if (bgr != -1) {
                ans = std::min(ans, bgr);
            }
            std::cout << ans << std::endl;
        }
    }
}
