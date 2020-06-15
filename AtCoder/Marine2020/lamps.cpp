#include <bits/stdc++.h>

int N, K;

std::vector<int> update(std::vector<int> &A) {
    std::vector<int> a_new(N, 0);
    for (int i = 0; i < N; i++) {
        for (int j = std::max(i - A[i], 0); j <= std::min(i + A[i], N - 1); j++) {
            a_new[j]++;
        }
    }
    return a_new;
}


int main() {
    std::cin >> N >> K;

    std::vector<int> A(N);
    for (int i = 0 ; i < N; i++) {
        std::cin >> A[i];
    }

    for (int i = 0; i < K; i++) {
        A = update(A);
    }
    std::cout << A[0];
    for (int i = 1; i < N; i++) {
        std::cout << " " << A[i];
    }
    std::cout << std::endl;
}
