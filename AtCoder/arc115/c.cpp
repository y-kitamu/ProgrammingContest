#include <bits/stdc++.h>


int main() {
    int N;
    std::cin >> N;

    std::vector<int> A(N, 1);
    for (int i = 2; i <= N; i++) {
        int min = 1;
        for (int j = 1; j <= std::sqrt(i); j++) {
            if (i % j == 0) {
                min = std::max(A[j - 1], min);
                min = std::max(A[i / j - 1], min);
            }
        }
        A[i - 1] = min + 1;
    }

    for (int i = 0; i < N; i++) {
        std::cout << A[i];
        if (i < N - 1) {
            std::cout << " ";
        }
    }
    std::cout << std::endl;
}
