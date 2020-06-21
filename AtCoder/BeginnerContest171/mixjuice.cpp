#include <bits/stdc++.h>


int main() {
    int N, K;
    std::cin >> N >> K;
    std::vector<int> price(N);
    for (int i = 0; i < N; i++) {
        std::cin >> price[i];
    }
    std::sort(price.begin(), price.end(), [](auto lhs, auto rhs) {return lhs < rhs;});
    int sum = 0;
    for (int i = 0; i < K; i++) {
        sum += price[i];
    }
    std::cout << sum << std::endl;
}
