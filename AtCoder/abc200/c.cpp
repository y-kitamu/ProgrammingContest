#include <bits/stdc++.h>


int main() {
    int N;
    std::cin >> N;

    std::vector<long long int> cnt(200, 0);
    for (int i = 0; i < N; i++) {
        int a;
        std::cin >> a;
        cnt[a % 200]++;
    }

    long long int sum = 0;
    for (int i = 0; i < 200; i++) {
        sum += cnt[i] * (cnt[i] - 1) / 2;
    }

    std::cout << sum << std::endl;
}
