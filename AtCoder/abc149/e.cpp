#include <bits/stdc++.h>


int main() {
    long long int N, M;
    std::cin >> N >> M;
    std::vector<long long int> A(N);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::sort(A.begin(), A.end(), std::greater<long long int>());

    long long int all = std::sqrt(M);
    long long int sum = 0;
    for (int i = 0; i < all; i++) {
        sum += A[i];
        sum *= 2;
    }
    long long int res = M - all * all;
    for (int i = 0; i < res; i++) {
        sum += A[i / 2] + A[all];
    }

    std::cout << sum << std::endl;
}
