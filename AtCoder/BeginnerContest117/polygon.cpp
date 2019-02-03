#include <iostream>

int main() {
    int N;
    std::cin >> N;

    int L[N];

    int max_idx = 0;
    for (int i = 0; i < N; i++) {
        std::cin >> L[i];
        if (L[max_idx] < L[i]) max_idx = i;
    }

    int total_len = 0;
    for (int i = 0; i < N; i++) {
        if (i != max_idx) {
            total_len += L[i];
        }
    }

    if (total_len > L[max_idx]) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }
}
