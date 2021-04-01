#include <bits/stdc++.h>


int main() {
    int A, B;
    std::cin >> A >> B;

    int ans = -1;
    for (int i = 0; i <= 1000; i++) {
        if (i * 8 / 100 == A && i * 10 / 100 == B) {
            ans = i;
            break;
        }
    }
    std::cout << ans << std::endl;
}
