#include <bits/stdc++.h>


int main() {
    int N, X;
    std::cin >> N >> X;

    X *= 100;
    int sum = 0;
    int idx = -1;
    for (int i = 0; i < N; i++) {
        int v, p;
        std::cin >> v >> p;
        sum += v * p;
        if (idx == -1 && sum > X) {
            idx = i + 1;
        }
    }
    std::cout << idx << std::endl;
}
