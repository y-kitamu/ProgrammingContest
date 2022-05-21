/**
 * @file d.cpp
 * @brief
 * @author Yusuke Kitamura <ymyk6602@gmail.com>
 * @date 2022-05-21 21:17:46
 */
#include <bits/stdc++.h>


int main() {
    long long N;
    std::cin >> N;

    std::map<long long, long long> cnts;
    for (int i = 0; i < N; i++) {
        long long a;
        std::cin >> a;
        cnts[a]++;
    }
    long long ans = N * (N - 1) * (N - 2) / 6;

    for (auto& pair : cnts) {
        long long c = pair.second;
        ans -= (long long)c * (c - 1ll) * (N - c) / 2ll;
        ans -= (long long)c * (c - 1ll) * (c - 2ll) / 6ll;
    }

    std::cout << ans << std::endl;
}
