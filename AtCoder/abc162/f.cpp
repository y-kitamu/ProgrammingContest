#include <bits/stdc++.h>


using ll = long long int;

int main() {
    int N;
    std::cin >> N;
    std::vector<ll> odd(N / 2 + 1, 0), even(N - N / 2 + 1, 0);
    for (int i = 0; i < N; i++) {
        ll val;
        std::cin >> val;
        if (i % 2 == 0) {
            even[i / 2 + 1] = even[i / 2] + val;
        } else {
            odd[i / 2 + 1] = odd[i / 2] + val;
        }
    }

    ll max = -1e17;
    // std::vector<ll> eo, oe, ee;
    std::vector<ll> eo(N / 2 + 2, 0);
    // even -> odd
    for (int i = 0; i <= N / 2; i++) {
        max = std::max(even[i] + odd[N / 2] - odd[i], max);
        eo[i + 1] = std::max(eo[i] + odd[i + 1] - odd[i], even[i] + odd[i + 1] - odd[i]);
        // eo.emplace_back(even[i] + odd[N / 2] - odd[i]);
    }
    if (N % 2 == 1) {
        // odd -> even & even -> even
        for (int i = 0; i <= N / 2; i++) {
            max = std::max(odd[i] + even[N / 2 + 1] - even[i + 1], max);
            max = std::max(even[i] + even[N / 2 + 1] - even[i + 1], max);
            // oe.emplace_back(odd[i] + even[N / 2 + 1] - even[i + 1]);
            // ee.emplace_back(even[i] + even[N / 2 + 1] - even[i + 1]);
        }
        // even -> odd -> even
        for (int i = 0; i <= N / 2; i++) {
            max = std::max(eo[i] + even[N / 2 + 1] - even[i + 1], max);
        }
    }

    // auto print_vec = [](auto& vec) {
    //     for (auto& val : vec) {
    //         std::cout << val << " ";
    //     }
    //     std::cout << std::endl;
    // };
    // print_vec(eo);
    // print_vec(oe);
    // print_vec(ee);

    std::cout << max << std::endl;
}
