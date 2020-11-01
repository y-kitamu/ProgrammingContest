#include <bits/stdc++.h>


int main() {
    const long long int MOD = 998244353;
    long long int A, B, C;
    std::cin >> A >> B >> C;

    long long int sum_a = (A + 1) * A / 2 % MOD;
    long long int sum_b = (B + 1) * B / 2 % MOD;
    long long int sum_c = (C + 1) * C / 2 % MOD;
    std::cout << ((sum_a * sum_b) % MOD) * sum_c % MOD  << std::endl;
}
