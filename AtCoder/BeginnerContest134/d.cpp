#include <bits/stdc++.h>

int main() {
    int N;
    std::cin >> N;
    std::vector<int> a(N);
    for (int i = 0; i < N; i++) {
        std::cin >> a[i];
    }

    std::vector<int> boxes(N, 0);
    int M = 0;
    for (int i = N - 1; i >= 0; i--) {
        int count = 0;
        for (int j = N / (i + 1); j > 1; j--) {
            count += boxes[j * (i + 1) - 1];
        }
        if (count % 2 != a[i]) {
            boxes[i] = 1;
            M++;
        }
    }
    std::cout << M << std::endl;
    for (int i = 0; i < N; i++) {
        if (boxes[i] == 1) {
            std::cout << i + 1;
            M--;
            if (M > 0) {
                std::cout << " ";
            }
        }
    }
    std::cout << std::endl;
}
