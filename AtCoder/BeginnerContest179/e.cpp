#include <bits/stdc++.h>


int main() {
    long long int N, M, X;
    std::cin >> N >> X >> M;

    long long int sum = 0;
    long long int a = X;

    std::vector<long long int> mods(M);
    for (long long int i = 0; i < M; i++) {
        mods[i] = (i * i) % M;
    }

    std::vector<int> count(M, -1);
    std::vector<int> sums(M, 0);
    for (int i = 0; i < N; i++) {
        if (count[a] == -1) {
            if (i == 0) {
                sums[i] = a;
            } else {
                sums[i] = sums[i - 1] + a;
            }
            count[a] = i;
            a = mods[a];
        } else {
            sum = sums[count[a]] + (N - count[a]) / (i - count[a]) * (sums[i] - sums[count[a]]) +
                sums[count[a] + (N - count[a]) % (count[a] - i)] - sums[count[a]];
            break;
        }
        if (a == 0) {
            sum = sums[i];
            break;
        }
    }
    std::cout << sum << std::endl;
}
