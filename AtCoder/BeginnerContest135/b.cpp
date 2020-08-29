#include <bits/stdc++.h>

int main() {
    int N;
    std::cin >> N;
    int count = 0;
    for (int i = 0; i < N; i++) {
        int val;
        std::cin >> val;
        if (val != i + 1) {
            count++;
        }
    }
    if (count > 2) {
        std::cout << "NO" << std::endl;
    } else {
        std::cout << "YES" << std::endl;
    }
}
