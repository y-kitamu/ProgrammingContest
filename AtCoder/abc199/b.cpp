#include <bits/stdc++.h>


int main() {
    int N;
    std::cin >> N;

    int min = 1000, max = 1;
    for (int i = 0; i < N; i++) {
        int a;
        std::cin >> a;
        max = std::max(max, a);
    }

    for (int i = 0; i < N; i++) {
        int b;
        std::cin >> b;
        min = std::min(min, b);
    }

    std::cout << std::max(min - max + 1, 0) << std::endl;
}
