#include <bits/stdc++.h>


int main() {
    long long int N;
    std::cin >> N;

    std::vector<long long int> A(N, 0);
    std::cin >> A[0];
    for (int i = 1; i < N; i++) {
        std::cin >> A[i];
        A[i] += A[i - 1];
    }

    long long int pos = 0;
    long long int max = 0;
    long long int inner_max = 0;
    for (int i = 0; i < N; i++) {
        max = std::max(pos + inner_max, max);
        pos += A[i];
        max = std::max(pos, max);
        inner_max = std::max(inner_max, A[i]);
    }
    std::cout << max << std::endl;
}
