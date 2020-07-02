#include <bits/stdc++.h>

int main() {
    long long int N;
    std::cin >> N;

    std::vector<long long int> f(N + 1, 0);

    long long int sum = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = i; j <= N; j += i) {
            f[j]++;
        }
        sum += f[i] * i;
    }
    std::cout << sum << std::endl;
}
