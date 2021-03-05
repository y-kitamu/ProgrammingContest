#include <bits/stdc++.h>


long long int GCD(long long int a, long long int b) {
    while (b > 0) {
        long long int tmp = b;
        b = a % b;
        a = tmp;
    }
    return a;
}


int main() {
    long long int A, B;
    std::cin >> A >> B;

    long long int gcd = GCD(A, B);
    long long int max = std::sqrt(gcd) + 1;

    long long int val = gcd;
    long long int cnt = 1;
    for (long long int i = 2; i <= max; i++) {
        if (val % i != 0) {
            continue;
        }
        cnt++;
        while (val % i == 0) {
            val /= i;
        }
        if (val == 1) {
            break;
        }
    }
    if (val > 1) {
        cnt++;
    }
    std::cout << cnt << std::endl;
}
