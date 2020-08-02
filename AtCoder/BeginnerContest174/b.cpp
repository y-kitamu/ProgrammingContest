#include <bits/stdc++.h>

int main() {
    long long int N, D;
    std::cin >> N >> D;

    int count = 0;
    for (int i = 0; i < N; i++) {
        long long int x, y;
        std::cin >> x >> y;
        if (std::sqrt(x * x + y * y) > D) {
        } else {
            count++;
        }
    }
    std::cout << count << std::endl;
}
