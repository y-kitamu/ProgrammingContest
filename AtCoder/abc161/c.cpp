#include <bits/stdc++.h>


int main() {
    long long int N, K;
    std::cin >> N >> K;

    long long int div = N / K;
    long long int res = std::min((div + 1) * K - N, N - div * K);
    std::cout << res << std::endl;
}
