#include <bits/stdc++.h>


int main() {
    int X;
    std::cin >> X;

    std::vector<bool> flag(1e6 + 1, true);
    for (int i = 2; i <= std::sqrt(1e6); i++) {
        if (flag[i] == false) {
            continue;
        }
        for (int j = 2; j <= flag.size() / i; j++) {
            flag[j * i] = false;
        }
    }

    for (int i = X;; i++) {
        if (flag[i]) {
            std::cout << i << std::endl;
            break;
        }
    }
}
