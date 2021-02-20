#include <bits/stdc++.h>


int main() {
    long long int N, V;
    std::cin >> N >> V;

    std::vector<long long int> a(N), b(N), c(N), d(N);

    for (int i = 0; i < N; i++) {
        std::cin >> a[i];
    }
    for (int i = 0; i < N; i++) {
        std::cin >> b[i];
    }
    for (int i = 0; i < N; i++) {
        std::cin >> c[i];
    }
    for (int i = 0; i < N; i++) {
        std::cin >> d[i];
    }

    std::vector<long long int> ab(N * N), cd(N * N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            ab[i * N + j] = a[i] + b[j];
            cd[i * N + j] = c[i] + d[j];
        }
    }

    std::sort(ab.begin(), ab.end());
    std::sort(cd.begin(), cd.end());

    long long int cnt = 0;
    for (int i = 0; i < N * N; i++) {
        auto left = std::lower_bound(cd.begin(), cd.end(), V - ab[i]);
        auto right = std::upper_bound(cd.begin(), cd.end(), V - ab[i]);
        cnt += right - left;
    }

    std::cout << cnt << std::endl;
}
