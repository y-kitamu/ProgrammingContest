#include <bits/stdc++.h>


int main() {
    int N;
    std::cin >> N;
    std::vector<int> a(N), b(N), p(N);
    int max_idx, max_weight = -1;
    for (int i = 0; i < N; i++) {
        std::cin >> a[i];
        if (max_weight < a[i]) {
            max_idx = i;
            max_weight = a[i];
        }
    }
    for (int i = 0; i < N; i++) {
        std::cin >> b[i];
    }
    bool flag = false;
    for (int i = 0; i < N; i++) {
        std::cin >> p[i];
        flag |= (a[i] != p[i] && a[i] <= b[p[i]]);
    }
    if (flag) {
        std::cout << -1 << std::endl;;
        return 0;
    }

    for (int i = 0; i < N; i++) {
        if (a[i] != p[i]) {
        }
    }
}
