/**
 * @file a.cpp
 * @brief
 * @author Yusuke Kitamura <ymyk6602@gmail.com>
 * @date 2022-04-24 20:57:17
 */
#include <bits/stdc++.h>


int main() {
    int N;
    std::cin >> N;

    std::vector<int> T(N);
    for (int i = 0; i < N; i++) {
        std::cin >> T[i];
    }

    long long ans = 1ll << T[0];
    long long mask = (1ll << 60) - 1ll;
    for (int i = 1; i < N; i++) {
        ans &= (mask << T[i]);
        ans += (1ll << T[i]);
        if (!(ans & (1ll << T[i]))) {
            ans += (1ll << T[i]);
        }
    }
    std::cout << ans << std::endl;
}
