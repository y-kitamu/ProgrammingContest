#include <bits/stdc++.h>


int main() {
    int N;
    std::cin >> N;
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        int val;
        std::cin >> val;
        if (i % 2 == 0 && val % 2 == 1) {
            cnt++;
        }
    }
    std::cout << cnt << std::endl;
}
