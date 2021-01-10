#include <bits/stdc++.h>


int main() {
    long long int N, C;
    std::cin >> N >> C;

    auto compare = [] (auto &lhs, auto &rhs) {
        return lhs.first > rhs.first;
    };
    std::priority_queue<std::pair<long long int, long long int>,
                        std::vector<std::pair<long long int, long long int>>,
                        decltype(compare)> que {compare};
    for (int i = 0; i < N; i++) {
        long long int a, b, c;
        std::cin >> a >> b >> c;
        que.push(std::make_pair(a, c));
        que.push(std::make_pair(b + 1, -c));
    }

    long long int sum = 0;
    long long int price = 0;
    long long int day = 1;
    while (!que.empty()) {
        auto pair = que.top();
        sum += (pair.first - day) * std::min(C, price);
        day = pair.first;
        que.pop();
        price += pair.second;
        while (!que.empty() && que.top().first == pair.first) {
            price += que.top().second;
            que.pop();
        }
    }
    std::cout << sum << std::endl;
}
