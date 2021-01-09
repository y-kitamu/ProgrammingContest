#include <bits/stdc++.h>


long long int calc(long long int n, long long int M) {
    long long int sq = M * M;
    long long int pow = 10;
    long long int ret = 1;
    while (n > 0) {
        if (n & 1) {
            ret = (ret * pow) % sq;
        }
        pow = (pow * pow) % sq;
        n >>= 1;
    }
    return (ret / M) % M;
}


int main() {
    long long int N, M;
    std::cin >> N >> M;

    std::cout << calc(N, M) << std::endl;;
}
