#include <bits/stdc++.h>


using ll = long long int;


class SegTree {};


int main() {
    int N;
    std::cin >> N;

    std::vector<ll> lhs(N), rhs(N);
    for (int i = 0; i < N; i++) {
        std::cin >> lhs[N - i - 1];
    }
    for (int i = 0; i < N; i++) {
        std::cin >> rhs[i];
    }

    ll sum = 0;
    for (int i = 0; i < N; i++) {
        sum += rhs[i];
    }

    auto comp_h = [](auto& lhs, auto& rhs) {
        if (lhs.second < rhs.second) {
            return true;
        } else if (lhs.second > rhs.second) {
            return false;
        }
        return lhs.first < rhs.first;
    };
    std::priority_queue<std::pair<ll, ll>, std::vector<std::pair<ll, ll>>, decltype(comp_h)> high{
        comp_h};
    for (int i = 0; i < N; i++) {
        high.push(std::make_pair(i, rhs[i]));
    }

    // SegTree seg(lhs);

    while (!high.empty()) {
        auto top = high.top();
        // seg.
    }


    std::cout << sum << std::endl;
}
