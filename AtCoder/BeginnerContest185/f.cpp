#include <bits/stdc++.h>


int main() {
    int N, Q;
    std::cin >> N >> Q;

    std::vector<long long int> a(N, 0);
    std::vector<long long int> sums(N + 1, 0);
    for (int i = 0; i < N; i++) {
        std::cin >> a[i];
        sums[i + 1] = sums[i] ^ a[i];
    }

    for (int i = 0; i < Q; i++) {
        long long int t, x, y;
        std::cin >> t >> x >> y;
        if (t == 1) {
            sums[N] = sums[N] ^ y ^ a[x - 1];
            a[x - 1] = a[x - 1] ^ y;
        } else if (t == 2) {
            long long int sum = sums[y] ^ sums[x - 1];
            std::cout << sum << std::endl;
        }
    }
}
