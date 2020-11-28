#include <bits/stdc++.h>


int main() {
    int n, k;
    std::cin >> n >> k;
    std::string s;
    std::cin >> s;

    for (int j = 0; j < k; j++) {
        std::string new_s = "";
        int mod = s.length();
        for (int i = 0; i < mod * 2; i += 2) {
            char i1 = s[(i + 1) % mod], i0 = s[i % mod];
            if ((i1 == 'R' && i0 == 'S') ||
                (i1 == 'P' && i0 == 'R') ||
                (i1 == 'S' && i0 == 'P')) {
                new_s += i1;
            } else {
                new_s += i0;
            }
        }
        s = new_s;
    }
    std::cout << s[0] << std::endl;
}
