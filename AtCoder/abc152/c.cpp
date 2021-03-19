#include <bits/stdc++.h>


int main() {
    int N;
    std::cin >> N;

    int cnt = 0;
    int min = 1e6;
    for (int i = 0; i < N; i++) {
        int p;
        std::cin >> p;
        if (p <= min) {
            min = p;
            cnt++;
        }
    }
    std::cout << cnt << std::endl;
}
