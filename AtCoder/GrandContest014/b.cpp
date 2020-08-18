#include <bits/stdc++.h>


int main() {
    int N, M;
    std::cin >> N >> M;
    std::vector<int> vec(N - 1, 0);
    for (int i = 0; i < M; i++) {
        int a, b;
        std::cin >> a >> b;
        a--; b--;
        if (a > b) {
            std::swap(a, b);
        }
        for (int i = a; i < b; i++) {
            vec[i]++;
        }
    }

    for (auto val : vec) {
        if (val % 2 != 0) {
            std::cout << "NO" << std::endl;
            return 0;
        }
    }
    std::cout << "YES" << std::endl;
}
