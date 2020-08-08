#include <bits/stdc++.h>

int main() {
    int N;
    std::cin >> N;
    std::vector<long long int> A(N);
    long long int sum = 0;
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
        sum += A[i];
    }
    sum /= 2;

    for (int i = 0; i < N; i++) {
        long long int val = 0;
        for (int j = i; j < N; j += 2) {
            val += A[j];
        }
        for (int j = i - 1; j >= 0; j -= 2) {
            val += A[j];
        }
        std::cout << (val - sum) * 2;
        if (i < N - 1) {
            std::cout << " ";
        }
    }
    std::cout << std::endl;
}
