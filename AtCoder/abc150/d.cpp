#include <bits/stdc++.h>


long long int GCD(long long int a, long long int b) { return b == 0 ? a : GCD(b, a % b); }

long long int LCM(long long int a, long long int b) { return a * (b / GCD(a, b)); }


int main() {
    long long int N, M;
    std::cin >> N >> M;
    std::vector<long long int> A(N);
    long long int lcm = 1;
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
        lcm = LCM(lcm, A[i]);
        if (lcm > M * 2) {
            std::cout << 0 << std::endl;
            return 0;
        }
    }

    if (lcm % 2 != 0) {
        std::cout << 0 << std::endl;
    }

    for (int i = 0; i < N; i++) {
        if ((lcm / A[i]) % 2 == 0) {
            std::cout << 0 << std::endl;
            return 0;
        }
    }

    lcm /= 2;
    std::cout << (M + lcm) / (lcm * 2) << std::endl;
}
