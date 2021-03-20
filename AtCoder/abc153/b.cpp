#include <bits/stdc++.h>


int main() {
    int H, N;
    std::cin >> H >> N;
    for (int i = 0; i < N; i++) {
        int val;
        std::cin >> val;
        H -= val;
    }
    if (H <= 0) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }
}
