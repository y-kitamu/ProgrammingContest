#include <bits/stdc++.h>

int gcd(int a, int b) {
    while (b > 0) {
        int tmp = b;
        b = a % b;
        a = tmp;
    }
    return a;
}


long long extGCD(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long d = extGCD(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

int main() {
    int T;
    std::cin >> T;
    for (int i =0; i < T; i++) {
        int N, S, K;
        std::cin >> N >> S >> K;

        int step = gcd(N, K);
        if (S % step != 0) {
            std::cout << -1 << std::endl;
            continue;
        }

        N /= step; S /= step; K /= step;
        long long int dst = N - S;
        long long int x, y;
        extGCD(N, K, x, y);
        if (y < 0) {
            y += N;
        }
        long long int res = (dst * y) % N;
        if (res < 0) {
            res += N;
        }
        std::cout << res << std::endl;
    }
}
