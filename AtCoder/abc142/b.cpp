#include <bits/stdc++.h>


int main() {
    int N, K;
    std::cin >> N >> K;

    int cnt = 0;
    for (int i = 0; i < N; i++) {
        int h;
        std::cin >> h;
        if (h >= K) {
            cnt++;
        }
    }

    std::cout << cnt << std::endl;
}
