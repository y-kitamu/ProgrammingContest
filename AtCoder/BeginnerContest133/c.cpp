#include <bits/stdc++.h>


int main() {
    long long int L, R;
    std::cin >> L >> R;

    if (R - L > 2019) {
        std::cout << 0 << std::endl;
        return 0;
    }

    long long int min = 10000;
    for (long long int i = L; i < R; i++) {
        for (long long int j = i + 1; j <= R; j++) {
            min = std::min((i * j) % 2019, min);
        }
    }
    std::cout << min << std::endl;
}
