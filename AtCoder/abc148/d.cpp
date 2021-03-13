#include <bits/stdc++.h>


int main() {
    int N;
    std::cin >> N;

    int cnt = 1;
    for (int i = 0; i < N; i++) {
        int val;
        std::cin >> val;
        if (val == cnt) {
            cnt++;
        }
    }
    if (cnt == 1) {
        std::cout << -1 << std::endl;
    } else {
        std::cout << N - (cnt - 1) << std::endl;
    }
}
