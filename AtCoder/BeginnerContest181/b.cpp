#include <bits/stdc++.h>


int main() {
    int N;
    std::cin >> N;
    long long int sum = 0;
    for (int i = 0; i < N; i++) {
        long long int a, b;
        std::cin >> a >> b;
        sum += (b - a + 1) * (b + a) / 2;
    }

    std::cout << sum << std::endl;
}
