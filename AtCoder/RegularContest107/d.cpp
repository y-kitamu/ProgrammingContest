#include <bits/stdc++.h>


long long int calc_count(int num) {

}

int main() {
    long long int MOD = 998244353;
    int N, K;
    std::cin >> N >> K;

    std::vector<int> counts(N, -1);
    counts[1] = 1;
    counts[2] = 1;
    counts[3] = 1;

    for (int i = N - K; i >= std::max(N / 2, K); i--) {
    }
}
