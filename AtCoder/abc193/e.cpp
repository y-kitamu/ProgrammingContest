#include <bits/stdc++.h>

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

long long GCD(long long a, long long b) {
    if (b == 0)
        return a;
    else
        return GCD(b, a % b);
}

int main() {
    int T;
    std::cin >> T;

    const long long int MAX = -1;

    for (int i = 0; i < T; i++) {
        long long int X, Y, P, Q;
        std::cin >> X >> Y >> P >> Q;

        long long int A = 2 * (X + Y);
        long long int B = P + Q;
        long long int N, M;
        long long int gcd = extGCD(A, B, N, M);
        long long int step = B / gcd;
        M *= -1;

        long long int min = MAX;
        for (long long int y = 0; y < Y; y++) {
            for (long long int q = 0; q < Q; q++) {
                long long int c = (P + q) - (X + y);
                if (c % gcd != 0) {
                    continue;
                }
                long long int factor = c / gcd;
                long long int n = N * factor;
                n %= step;
                if (n < 0) {
                    n += step;
                }
                long long int time = n * A + X + y;
                if (min == MAX) {
                    min = time;
                }
                min = std::min(min, time);
            }
        }

        if (min == MAX) {
            std::cout << "infinity" << std::endl;
        } else {
            std::cout << min << std::endl;
        }
    }
}
