#include <bits/stdc++.h>


int main() {
    long long int N;
    std::cin >> N;

    std::vector<long long int> A(N + 1);
    for (long long int i = 0; i < N + 1; i++) {
        std::cin >> A[i];
    }
    std::vector<long long int> B(N);
    for (long long int i = 0; i < N; i++) {
        std::cin >> B[i];
    }

    long long int count = 0;
    for (long long int i = N - 1; i >= 0; i--) {
        if (A[i + 1] >= B[i])  {
            count += B[i];
            B[i] = 0;
        } else {
            count += A[i + 1];
            B[i] -= A[i + 1];
        }
        count += std::min(A[i], B[i]);
        A[i] = std::max(A[i] - B[i], 0ll);
    }
    std::cout << count << std::endl;
}
