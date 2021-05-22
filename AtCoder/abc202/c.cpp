#include <bits/stdc++.h>


int main() {
    int N;
    std::cin >> N;

    std::vector<long long int> A(N, 0), B(N, 0), C(N, 0), bc(N, 0);

    for (int i = 0; i < N; i++) {
        int val;
        std::cin >> val;
        A[val - 1]++;
    }
    for (int i = 0; i < N; i++) {
        std::cin >> B[i];
        B[i]--;
    }
    for (int i = 0; i < N; i++) {
        int val;
        std::cin >> val;
        bc[B[val - 1]]++;
    }

    long long int res = 0;
    for (int i = 0; i < N; i++) {
        res += A[i] * bc[i];
    }
    std::cout << res << std::endl;
}
