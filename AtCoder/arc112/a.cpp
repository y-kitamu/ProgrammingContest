#include <bits/stdc++.h>


int main() {
    int T;
    std::cin >> T;

    for (int i = 0; i < T; i++) {
        long long int L, R;
        std::cin >> L >> R;
        long long int res = 0;
        if (R - 2 * L >= 0) {
            res = (R - 2 * L + 2) * (R - 2 * L + 1) / 2;
        }
        std::cout << res << std::endl;
    }
}
