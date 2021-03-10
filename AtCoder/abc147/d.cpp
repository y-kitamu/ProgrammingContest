#include <bits/stdc++.h>


int main() {
    long long int MOD = 1e9 + 7;
    int N;
    std::cin >> N;
    std::vector<long long int> A(N);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    long long int sum = 0;
    for (int j = 0; j <= 60; j++) {
        long long int cnt0 = 0, cnt1 = 0;
        for (int i = 0; i < N; i++) {
            if (A[i] >> j & 1) {
                cnt1++;
            } else {
                cnt0++;
            }
        }
        long long int cnt = (cnt0 * cnt1) % MOD;
        sum = (sum + (((1ll << j) % MOD) * cnt % MOD)) % MOD;
        // std::cout << cnt << " , " << sum << std::endl;
    }
    std::cout << sum << std::endl;
}
