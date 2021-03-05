#include <bits/stdc++.h>


int main() {
    int N, M;
    std::cin >> N >> M;

    std::vector<int> a(M), b(M), c(M);
    for (int i = 0; i < M; i++) {
        std::cin >> a[i] >> b[i];
        for (int j = 0; j < b[i]; j++) {
            c[i] |= 1 << j;
        }
    }

    for (int i = 0; i < 1 << N; i++) {
    }
}
