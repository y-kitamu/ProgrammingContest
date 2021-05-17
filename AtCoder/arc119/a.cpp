#include <bits/stdc++.h>


int main() {
    long long int N;
    std::cin >> N;

    long long int res = N;
    for (int i = 0; i < 64; i++) {
        long long int sum = 0;
        long long int b2 = (1ll << i);
        sum = i + N % b2 + N / b2;
        res = std::min(sum, res);
    }
    std::cout << res << std::endl;
}
