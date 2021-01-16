#include <bits/stdc++.h>

int main() {
    int N;
    std::cin >> N;
    std::vector<long long int> a(N), b(N);
    for (int i = 0; i < N; i++) {
        std::cin >> a[i];
    }
    for (int i = 0; i < N; i++) {
        std::cin >> b[i];
    }

    long long int max_a = 1, max_b = 1;
    long long int max = 1;
    // long long int max = 1;
    for (int i = 0; i < N; i++) {
        max_a = std::max(max_a, a[i]);
        if (b[i] >= max_b) {
            max_b = b[i];
            max = max_a * max_b;
        } else if (max_a * b[i] >= max) {
            max_b = b[i];
            max = max_a * max_b;
        }
        std::cout << max << std::endl;
    }
}
