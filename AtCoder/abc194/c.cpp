#include <bits/stdc++.h>


using ll = long long int;

int main() {
    int N;
    std::cin >> N;
    std::vector<ll> A(N);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    long long int lhs = 0;
    long long int rhs = 0;
    for (int i = 0; i < N; i++) {
        lhs += A[i] * A[i];
        rhs += A[i];
    }
    std::cout << N * lhs - rhs * rhs << std::endl;
}
