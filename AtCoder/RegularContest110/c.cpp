#include <bits/stdc++.h>


int main() {
    int N;
    std::cin >> N;

    int start_idx = 0, min_idx = 0;
    bool flag = false;
    std::vector<int> P(N);
    for (int i = 0; i < N; i++) {
        std::cin >> P[i];
        flag |= P[i] == i + 1;
    }
    if (flag) {
        std::cout << -1 << std::endl;
        return 0;
    }

    std::vector<int> order;
    while (min_idx < N - 1) {
        for (int i = start_idx; i < N; i++) {
            if (start_idx + 1 == P[i]) {
                start_idx = i;
                break;
            }
        }
        if (start_idx == min_idx) {
            std::cout << -1 << std::endl;
            return 0;
        }

        for (int i = start_idx; i > min_idx; i--) {
            std::swap(P[i], P[i - 1]);
            order.emplace_back(i);
        }
        bool flag = true;
        for (int i = min_idx; i < start_idx; i++) {
            flag &= P[i] == i + 1;
        }
        if (!flag) {
            std::cout << -1 << std::endl;
            return 0;
        }
        min_idx = start_idx;
    }

    for (int i = 0; i < N - 1; i++) {
        printf("%d\n", order[i]);
    }
}
