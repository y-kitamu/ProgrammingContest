#include <bits/stdc++.h>


int main() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    int maximum = 0;
    for (int l = 0; l < N; l++) {
        int min = A[l];
        int max = A[l];
        for (int r = l + 1; r < N; r++) {
            min = std::min(min, A[r]);
            max = std::max(max, min * (r - l + 1));
        }
        maximum = std::max(maximum, max);
    }
    std::cout << maximum << std::endl;
}
