#include <bits/stdc++.h>


int main() {
    long long int N;
    std::cin >> N;

    long long int sq = std::sqrt(2 * N) + 1;
    int cnt = 0;
    for (int i = 1; i <= sq; i++) {
        if (2 * N % i == 0 && 2 * N / i > i) {
            int j = 2 * N / i;
            if ((i + j) % 2 != 0) {
                cnt += 2;
            }
        }
    }

    std::cout << cnt << std::endl;
}
