#include <bits/stdc++.h>


int main() {
    int N;
    std::cin >> N;
    std::vector<int> A(N);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<long long int> sum(N);
    sum[0] = A[0];
    for (int i = 1; i < N; i++) {
        sum[i] = sum[i - 1] + A[i];
    }

    std::vector<long long int> res(N);
    long long int max = A[0];
    res[0] = sum[0];
    std::cout << res[0] + max << std::endl;
    for (long long int i = 1; i < N; i++) {
        max = std::max(max, (long long int)A[i]);
        res[i] += res[i - 1] + sum[i];
        std::cout << res[i] + max * (i + 1) << std::endl;
    }
}
