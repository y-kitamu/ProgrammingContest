#include <bits/stdc++.h>


int main() {
    int N;
    std::cin >> N;
    std::vector<int> diff(N);

    for (int i = 0; i < N; i++) {
        std::cin >> diff[i];
    }

    std::sort(diff.begin(), diff.end());
    std::cout << diff[N / 2] - diff[N / 2 - 1] << std::endl;
}
