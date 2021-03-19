#include <bits/stdc++.h>


long long int mod_pow(long long int n, long long int r, long long int mod) {
    long long int pow = n;
    long long int res = 1;
    while (r > 0) {
        if (r & 1) {
            res = (res * pow) % mod;
        }
        pow = (pow * pow) % mod;
        r >>= 1;
    }
    return res;
}


int main() {
    long long int N;
    std::cin >> N;

    std::vector<long long int> A(N);
    std::vector<std::map<int, int>> primes(N);
    std::map<int, int> lcms;
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];

        int val = A[i];
        int min = std::sqrt(A[i]);
        for (int j = 2; j <= min; j++) {
            int cnt = 0;
            while (val % j == 0) {
                val /= j;
                cnt++;
            }
            if (cnt > 0) {
                primes[i][j] = cnt;

                if (lcms.find(j) == lcms.end()) {
                    lcms[j] = cnt;
                } else {
                    lcms[j] = std::max(lcms[j], cnt);
                }
            }
        }
        if (val > 1) {
            primes[i][val] = 1;
            if (lcms.find(val) == lcms.end()) {
                lcms[val] = 1;
            }
        }
    }

    long long int MOD = 1e9 + 7;
    long long int sum = 0;
    for (auto& factors : primes) {
        long long int val = 1;
        for (auto& pair : lcms) {
            int cnt = pair.second;
            if (factors.find(pair.first) != factors.end()) {
                cnt -= factors[pair.first];
            }
            val = (val * mod_pow(pair.first, cnt, MOD)) % MOD;
        }
        // std::cout << val << std::endl;
        sum = (sum + val) % MOD;
    }
    std::cout << sum << std::endl;
}
