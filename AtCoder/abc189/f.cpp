#include <bits/stdc++.h>


int main() {
    int N, M, K;
    std::cin >> N >> M >> K;

    std::vector<long long int> a(K);
    for (int i = 0; i < K; i++) {
        std::cin >> a[i];
    }

    std::vector<long long int> mas(N + M, 0);
    mas[0] = 1;
    int idx = 0;
    long long int sum = 1;
    long long int rou = 0;
    long long int failed = 0;
    for (int i = 1; i < N + M; i++) {
        mas[i] = sum;
        if (idx >= K || a[idx] != i) {
            rou += sum;
        }

        if (i - M >= 0) {
            sum -= mas[i - M];
        }

        if (idx < K && a[idx] == i) {
            failed += mas[i];
            idx++;
        } else if (i < N) {
            sum += mas[i];
        }
    }

    long long int success = 0;
    for (int i = N; i < N + M; i++) {
        success += mas[i];
    }

    if (success == 0) {
        std::cout << -1 << std::endl;
        return 0;
    }

    std::cout << (double)rou * (success + failed) / (success * success) << std::endl;
}
