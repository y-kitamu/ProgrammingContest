#include <bits/stdc++.h>


int main() {
    int K;
    std::cin >> K;

    int val = 7;
    int mod = val % K;
    for (int i = 0; i < K; i++) {
        if (mod == 0) {
            std::cout << i + 1 << std::endl;
            return 0;
        }
        val = (val * 10) % K;
        mod = (mod + val) % K;
    }
    std::cout << -1 << std::endl;
}
