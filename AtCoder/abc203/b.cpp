#include <bits/stdc++.h>


int main() {
    int N, K;
    std::cin >> N >> K;

    int sum = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= K; j++) {
            sum += i * 100 + j;
        }
    }

    std::cout << sum << std::endl;
}
