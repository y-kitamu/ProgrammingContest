#include <bits/stdc++.h>


int main() {
    long long int N;
    std::cin >> N;

    std::vector<long long int> prices(N);
    for (int i = 0; i < N; i++) {
        std::cin >> prices[i];
    }

    long long int money = 1000;
    long long int stock = 0;
    for (int i = 0; i < N - 1; i++) {
        int diff = prices[i + 1] - prices[i];
        if (diff >= 0 && stock == 0) {
            stock = money / prices[i];
            money -= stock * prices[i];
        }
        if (diff <= 0 && stock > 0) {
            money += prices[i] * stock;
            stock = 0;
        }
    }
    if (stock > 0) {
        money += prices[N - 1] * stock;
    }
    std::cout << money << std::endl;
}
