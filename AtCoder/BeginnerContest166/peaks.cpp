#include <iostream>
#include <vector>


int main() {
    int N, M;
    std::cin >> N >> M;

    std::vector<int> heights(N);
    for (int i = 0; i < N; i++) {
        std::cin >> heights[i];
    }

    std::vector<int> is_heighest(N, 1);
    for (int i = 0; i < M; i++) {
        int a, b;
        std::cin >> a >> b;
        a--;
        b--;
        if (heights[a] > heights[b]) {
            is_heighest[b] = 0;
        }
        if (heights[b] > heights[a]) {
            is_heighest[a] = 0;
        }
        if (heights[a] == heights[b]) {
            is_heighest[a] = 0;
            is_heighest[b] = 0;
        }
    }

    int sum = 0;
    for (auto && val : is_heighest) {
        sum += val;
    }

    std::cout << sum << std::endl;
}
