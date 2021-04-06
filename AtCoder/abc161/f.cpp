#include <bits/stdc++.h>


int main() {
    long long int N;
    std::cin >> N;

    auto judge = [](long long int val, long long int i) {
        while (val % i == 0) {
            val /= i;
        }
        return val % i == 1;
    };

    if (N == 2) {
        std::cout << 1 << std::endl;
        return 0;
    }

    long long int cnt = 2;  // K = N - 1, K = N
    for (long long int i = 2; i <= std::sqrt(N); i++) {
        if (N % i == 0) {
            if (judge(N, i)) {
                cnt++;
            }
            if (i != N / i && judge(N, N / i)) {
                cnt++;
            }
        }
    }

    for (long long int i = 2; i <= std::sqrt(N - 1); i++) {
        if ((N - 1) % i == 0) {
            long long int div = (N - 1) / i;
            if (i == div) {
                cnt++;
            } else {
                cnt += 2;
            }
        }
    }
    std::cout << cnt << std::endl;
}
