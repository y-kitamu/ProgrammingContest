#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>

int main() {
    int NUMBERS[9] = {2, 5, 5, 4, 5, 6, 3, 7, 6};
    int N, M;

    std::cin >> N >> M;

    std::vector<std::pair<int, int>> enable_numbers(M);
    for (int i = 0; i < M; i++) {
        int num;
        std::cin >> num;
        enable_numbers[i] = std::make_pair(num, NUMBERS[num - 1]);
    }

    
}
