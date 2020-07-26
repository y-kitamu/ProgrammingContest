#include <bits/stdc++.h>


int main() {
    int N, L;
    std::cin >> N >> L;

    int flavor = 0;
    for (int i = 0 ; i < N; i++) {
        flavor += i + L;
    }

    if (L > 0) {
        flavor -= L;
    } else if (L + N - 1 < 0) {
        flavor -= L + N - 1;
    }

    std::cout << flavor << std::endl;
}
