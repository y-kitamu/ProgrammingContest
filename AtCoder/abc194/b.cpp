#include <bits/stdc++.h>

int main() {
    int N;
    std::cin >> N;

    std::vector<int> A(N), B(N);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i] >> B[i];
    }

    int min = 1e9;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) {
                min = std::min(A[i] + B[j], min);
            } else {
                min = std::min(std::max(A[i], B[j]), min);
            }
        }
    }
    std::cout << min << std::endl;
}
