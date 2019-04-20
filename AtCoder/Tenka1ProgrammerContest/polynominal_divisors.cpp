#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

int main() {
    long long N;
    std::cin >> N;

    std::vector<long long> a(N + 1);
    long long plus, minus, gcd;
    std::cin >> a[N];
    plus = minus = a[N];
    gcd = std::abs(a[N]);

    auto calc_gcd = [] (long long lhs, long long rhs) {
        if (lhs == 0 || rhs == 0) {
            return (long long)0;
        }
        while (lhs != rhs) {
            if (lhs > rhs) lhs = lhs - rhs;
            else rhs = rhs - lhs;
        }
        return lhs;
    };

    for (long long i = N - 1; i >= 0; i--) {
        std::cin >> a[i];
        gcd = calc_gcd(gcd, std::abs(a[i]));

        if (i % 2 == 0) {
            plus += a[i];
            minus += a[i];
        } else {
            plus += a[i];
            minus -= a[i];
        }
    }

    std::vector<int> primes;
    for (int j = 2; j < std::ceil(std::sqrt(gcd)); j++) {
        if (gcd % j == 0) {
            gcd /= j;
            primes.push_back(j);
            if (gcd == 1) break;
        }
    }
    if (gcd != 1) primes.push_back(gcd);

    plus = std::abs(plus) / gcd;
    minus = std::abs(minus) / gcd;
    long long a0 = a[0] / gcd;

    long long mini = std::min(std::min(plus, minus), a0);

    for (int i = 2; i < mini + 1; i++) {
        if (plus % i == 0 && minus % i == 0 && a0  % i == 0) {
            primes.push_back(i);
            plus /= i;
            minus /= i;
            a0 /= i;
             if (plus == 1 || minus == 1 || a0 == 1) break;
        }
    }
    std::sort(primes.begin(), primes.end(), [](const auto &lhs , const auto &rhs) { return lhs < rhs; });
    for (auto i : primes) {
        std::cout << i << std::endl;
    }
}
