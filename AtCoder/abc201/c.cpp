#include <bits/stdc++.h>


int main() {
    std::string S;
    std::cin >> S;
    int pos = 0, ev = 0;
    for (int i = 0; i < 10; i++) {
        if (S[i] == 'o') {
            pos++;
        } else if (S[i] == '?') {
            ev++;
        }
    }

    if (pos == 4) {
        std::cout << 24 << std::endl;
    } else if (pos == 3) {
        std::cout << ev * 24 + 6 * 6 << std::endl;
    } else if (pos == 2) {
        int res = ev * ev * 12 + ev * 24 + 8 + 6;
        std::cout << res << std::endl;
    } else if (pos == 1) {
        int res = ev * ev * ev * 4 + ev * ev * 6 + ev * 4 + 1;
        std::cout << res << std::endl;
    } else if (pos == 0) {
        int res = ev * ev * ev * ev;
        std::cout << res << std::endl;
    } else {
        std::cout << 0 << std::endl;
    }
}
