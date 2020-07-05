#include <bits/stdc++.h>


int main() {
    int N;
    std::cin >> N;

    std::vector<long long int> A(N);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::sort(A.begin(), A.end(), [](auto lhs, auto rhs) { return lhs > rhs; });
    long long int cnt = A[0];
    for (int i = 2; i < N; i++) {
        cnt += A[i / 2];
    }
    std::cout << cnt << std::endl;
}
