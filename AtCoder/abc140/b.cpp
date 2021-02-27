#include <bits/stdc++.h>


int main() {
    int N;
    std::cin >> N;

    long long int sum = 0;
    std::vector<int> A(N), C(N - 1);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }
    for (int i = 0; i < N; i++) {
        int val;
        std::cin >> val;
        sum += val;
    }
    for (int i = 0; i < N - 1; i++) {
        std::cin >> C[i];
    }

    for (int i = 0; i < N - 1; i++) {
        if (A[i + 1] - A[i] == 1) {
            sum += C[A[i] - 1];
        }
    }
    std::cout << sum << std::endl;
}
