#include <bits/stdc++.h>


int main() {
    int N;
    std::cin >> N;
    std::vector<int> L(N);
    for (int i = 0; i < N; i++) {
        std::cin >> L[i];
    }

    std::sort(L.begin(), L.end());

    int cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            int length = L[i] + L[j];
            auto itr = std::lower_bound(L.begin(), L.end(), length);
            int idx = std::distance(L.begin(), --itr);
            cnt += std::max(idx - j, 0);
        }
    }
    std::cout << cnt << std::endl;
}
