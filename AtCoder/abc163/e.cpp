#include <bits/stdc++.h>

using ll = long long int;

template <class T, class Comp>
std::vector<int> index_sort(std::vector<T>& vec, Comp compare) {
    std::vector<int> idx(vec.size());
    std::iota(idx.begin(), idx.end(), 0);

    std::sort(idx.begin(), idx.end(),
              [&vec, &compare](auto& lhs, auto& rhs) { return compare(vec[lhs], vec[rhs]); });
    return idx;
}


int main() {
    int N;
    std::cin >> N;

    std::vector<ll> A(N);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    auto idx = index_sort(A, std::greater<ll>());

    std::vector<std::vector<ll>> dp(N, std::vector<ll>(N, 0));

    for (int i = 0; i < N; i++) {
        for (int j = N - 1; j >= i; j--) {
            ll ci = i + N - 1 - j;
            if (i < N - 1) {
                ll val = std::abs(idx[ci] - i) * A[idx[ci]];
                dp[i + 1][j] = std::max(dp[i][j] + val, dp[i + 1][j]);
            }
            if (j > i) {
                ll val = std::abs(j - idx[ci]) * A[idx[ci]];
                dp[i][j - 1] = std::max(dp[i][j] + val, dp[i][j - 1]);
            }
        }
    }

    ll max = 0;
    for (int i = 0; i < N; i++) {
        max = std::max(dp[i][i] + std::abs(idx[N - 1] - i) * A[idx[N - 1]], max);
    }
    std::cout << max << std::endl;
}
