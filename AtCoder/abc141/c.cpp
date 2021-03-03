#include <bits/stdc++.h>


int main() {
    int N, K, Q;
    std::cin >> N >> K >> Q;
    std::vector<int> pt(N, 0);

    for (int i = 0; i < Q; i++) {
        int val;
        std::cin >> val;
        pt[--val]++;
    }

    for (int i = 0; i < N; i++) {
        if (Q - pt[i] >= K) {
            std::cout << "No" << std::endl;
        } else {
            std::cout << "Yes" << std::endl;
        }
    }
}
