#include <iostream>

int main() {
    int cnt[4] = {};
    for (int i = 0; i < 6; i++) {
        int val;
        std::cin >> val;
        cnt[val - 1]++;
    }

    int p1 = 0, p2 = 0;
    for (int i = 0; i < 4; i++) {
        if (cnt[i] == 1) {
            p1++;
        } else if (cnt[i] == 2) {
            p2++;
        }
    }

    if (p1 == 2 && p2 == 2) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }
}
