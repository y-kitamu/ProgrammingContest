#include <bits/stdc++.h>


int main() {
    long long int N, K;
    std::cin >> N >> K;

    for (int i = 0; i < K; i++) {
        if (N % 200 == 0) {
            N /= 200;
        } else {
            N = N * 1000 + 200;
        }
    }
    std::cout << N << std::endl;
}
