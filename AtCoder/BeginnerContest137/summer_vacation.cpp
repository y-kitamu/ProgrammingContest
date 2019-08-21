#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N, M;
    std::cin >> N >> M;
    std::vector<std::pair<int, int>> arbeits;

    for (int i = 0; i < N; i++) {
        int a, b;
        std::cin >> a >> b;
        arbeits.emplace_back(std::make_pair(a, b));
    }

    std::sort(arbeits.begin(), arbeits.end(),
              [](const auto &lhs, const auto &rhs) {return lhs.second > rhs.second;});

    std::vector<bool> flag(M, true);

    int revenue = 0;
    for (auto && beit : arbeits) {
        for (int i = M - beit.first; i >= 0; i--) {
            if (flag[i]) {
                revenue += beit.second;
                flag[i] = false;
                break;
            }
        }
    }
    std::cout << revenue << std::endl;
}
