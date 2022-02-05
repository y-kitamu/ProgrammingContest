#include <bits/stdc++.h>


int main() {
    long long int MOD = 998244353;
    long long int N;
    std::cin >> N;

    long long int sum = 0;
    long long int base = 1;
    while (base * 10 <= N) {
        long long int add = base * 10 - base + 1;
        long long int cnt = add - 1;
        if (add % 2 == 0) {
            add /= 2;
        } else {
            cnt /= 2;
        }
        sum = (sum + (add % MOD) * (cnt % MOD)) % MOD;
        base *= 10;
    }
    long long int max = N - base + 1;
    long long int add = max + 1;
    long long int cnt = add - 1;
    if (add % 2 == 0) {
        add /= 2;
    } else {
        cnt /= 2;
    }
    sum = (sum + (add % MOD) * (cnt % MOD)) % MOD;
    std::cout << sum << std::endl;
}
