#include <bits/stdc++.h>


int main() {
    int N;
    std::cin >> N;

    int cnt = 0;
    for (int i = 1; i < N; i++) {
        cnt += (N - 1) / i;
    }

    std::cout << cnt << std::endl;
}
