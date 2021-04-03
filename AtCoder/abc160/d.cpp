#include <bits/stdc++.h>


int main() {
    int N, X, Y;
    std::cin >> N >> X >> Y;
    X--;
    Y--;

    std::vector<int> nums(N - 1, 0);
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            int min = std::min(j - i, std::abs(i - X) + std::abs(j - Y) + 1);
            nums[min - 1]++;
            // std::cout << i << " " << j << " " << min << std::endl;
        }
    }

    for (int i = 0; i < N - 1; i++) {
        std::cout << nums[i] << std::endl;
    }
}
