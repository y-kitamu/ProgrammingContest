#include <bits/stdc++.h>


int main() {
    long long int N;
    std::cin >> N;

    if (N % 2 == 1) {
        std::cout << 0 << std::endl;
    } else {
        long long int cnt = 0;
        while (N > 0) {
            N /= 5;
            cnt += N / 2;
        }
        std::cout << cnt << std::endl;
    }
}
