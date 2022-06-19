/**
 * @file a.cpp
 * @brief
 * @author Yusuke Kitamura <ymyk6602@gmail.com>
 * @date 2022-06-19 20:58:59
 */
#include <bits/stdc++.h>


long long int reverse(long long int val) {
    long long int res = 0;
    while (val > 0) {
        res = res * 10 + val % 10;
        val /= 10;
    }
    return res;
}


int main() {
    long long int N, K;
    std::cin >> N >> K;

    long long int revk = reverse(K);
    if (K > revk) {
        std::cout << 0 << std::endl;
        return 0;
    }

    int cnt = 0;
    long long int cur = K;
    while (cur <= N) {
        cnt++;
        cur *= 10;
    }

    if (K != revk) {
        cur = revk;
        while (cur <= N) {
            cnt++;
            cur *= 10;
        }
    }

    std::cout << cnt << std::endl;
}
