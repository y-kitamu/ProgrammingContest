#include <iostream>
#include <vector>


int main() {
    int N, K;
    std::cin >> N >> K;

    std::vector<int> count(N, 1);

    for (int i = 0; i < K; i++) {
        int d;
        std::cin >> d;
        for (int j = 0; j < d; j++) {
            int idx;
            std::cin >> idx;
            count[idx - 1] = 0;
        }
    }

    int sum = 0;
    for (int i = 0; i < N; i++) {
        sum += count[i];
    }

    std::cout << sum << std::endl;
}
