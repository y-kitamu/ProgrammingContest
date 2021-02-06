#include <bits/stdc++.h>


int main() {
    int N, X;
    std::cin >> N >> X;
    std::vector<int> A(N, -1);
    int idx = 0;
    for (int i = 0; i < N; i++) {
        int a;
        std::cin >> a;
        if (X != a) {
            A[idx] = a;
            idx++;
        }
    }

    if (idx > 0) {
        std::cout << A[0];
        for (int i = 1; i < idx; i++) {
            std::cout << " " << A[i];
        }
    }
    std::cout << std::endl;
}
