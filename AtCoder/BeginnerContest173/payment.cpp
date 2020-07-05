#include <bits/stdc++.h>

int main() {
    int N;
    std::cin >> N;
    N = 1000 - N % 1000;
    if (N == 1000) {
        std::cout << 0 << std::endl;
    } else {
        std::cout << N << std::endl;
    }
}
