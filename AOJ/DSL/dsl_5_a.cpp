#include <bits/stdc++.h>


int main() {
    int N, T;
    std::cin >> N >> T;
    std::vector<int> diff(T, 0);
    for (int i = 0; i < N; i++) {
        int l, r;
        std::cin >> l >> r;
        diff[l]++;
        diff[r]--;
    }

    int customer = 0;
    int maximum = 0;
    for (int i = 0; i < T; i++) {
        customer += diff[i];
        maximum = std::max(maximum, customer);
    }

    std::cout << maximum << std::endl;
}
