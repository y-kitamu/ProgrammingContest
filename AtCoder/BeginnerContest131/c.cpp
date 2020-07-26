#include <bits/stdc++.h>


long long int gcd(long long int m, long long int n) {
    while (m % n != 0) {
        long long int tmp = m % n;
        m = n;
        n = tmp;
    }
    return n;
}

int main() {
    long long int A, B, C, D;
    std::cin >> A >> B >> C >> D;

    long long int cs = B / C - (A - 1) / C;
    long long int ds = B / D - (A - 1) / D;

    long long int cd = C * D / gcd(C, D);
    long long int cds = B / cd - (A - 1) / cd;

    std::cout << (B - A + 1) - (cs + ds - cds) << std::endl;
}
