#include <bits/stdc++.h>


int main() {
    int N;
    std::cin >> N;

    long long int MAX = 1000000000000000000;
    long long int sum = 1;
    bool overflow = false;
    bool zero = false;

    for (int i = 0; i < N; i++) {
        long long int n;
        std::cin >> n;
        if (n == 0) {
            zero = true;
        } else {
            long long int prev = sum;
            sum *= n;
            if ((double)prev * (double)n > (double)MAX) {
                overflow = true;
            }
            if (sum > MAX) {
                overflow = true;
            }
        }
    }

    if (zero) {
        std::cout << 0 << std::endl;
        return 0;
    }
    if (overflow) {
        std::cout << -1 << std::endl;
        return 0;
    }

    std::cout << sum << std::endl;
}
