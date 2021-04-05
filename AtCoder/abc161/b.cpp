#include <bits/stdc++.h>


int main() {
    int M, N;
    std::cin >> N >> M;
    std::vector<int> a(N);
    for (int i = 0; i < N; i++) {
        std::cin >> a[i];
    }

    int sum = std::accumulate(a.begin(), a.end(), 0);
    int cnt = 0;
    for (auto& val : a) {
        if (val * 4 * M >= sum) {
            cnt++;
        }
    }

    if (cnt >= M) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }
}
