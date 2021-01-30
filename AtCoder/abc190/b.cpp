#include <bits/stdc++.h>


int main() {
    int N, S, D;
    std::cin >> N >> S >> D;
    bool flag = false;
    for (int i = 0; i < N; i++) {
        int x, y;
        std::cin >> x >> y;
        flag |= (x < S && y > D);
    }
    if (flag) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }
}
