/**
 * @file d.cpp
 * @brief
 * @author Yusuke Kitamura <ymyk6602@gmail.com>
 * @date 2022-05-08 21:17:28
 */
#include <bits/stdc++.h>


int main() {
    long long N;
    std::cin >> N;
    long long max = std::pow(N, 1.0 / 3.0) + 1;

    long long int ans = 0;
    std::vector<long long> cnt(max + 1, 0);
    std::vector<long long> vals;
    for (long long i = 2; i <= max; i++) {
        if (cnt[i] > 0) {
            continue;
        }
        if (i * i * i > N) {
            break;
        }
        long long val = i * i * i;
        ans += std::distance(vals.begin(), std::upper_bound(vals.begin(), vals.end(), N / val));

        vals.emplace_back(i);
        for (long long j = i; j <= max; j += i) {
            cnt[j] = 1;
        }
    }
    std::cout << ans << std::endl;
}
