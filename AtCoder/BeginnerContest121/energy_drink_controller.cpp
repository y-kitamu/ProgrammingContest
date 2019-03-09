#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

int main() {
    int N, M;
    std::cin >> N >> M;
    
    std::vector<std::pair<long, long>> D(N);
    long A, B;
    for (int i = 0; i < N; i++) {
        std::cin >> A >> B;
        D[i] = std::make_pair(A, B);
    }

    std::sort(D.begin(), D.end(), [] (const auto &lhs, const auto &rhs) {
        return lhs.first < rhs.first;
    });

    int res = M;
    long price = 0;
    
    for (auto && drink : D) {
        if (res <= drink.second) {
            price += res * drink.first;
            break;
        }
        price += drink.first * drink.second;
        res -= drink.second;
    }

    std::cout << price << std::endl;
}
