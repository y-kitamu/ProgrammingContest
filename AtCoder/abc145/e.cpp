#include <bits/stdc++.h>


std::vector<int> index_sort(std::vector<int>& vec) {
    std::vector<int> indices(vec.size());
    std::iota(indices.begin(), indices.end(), 0);

    std::sort(indices.begin(), indices.end(),
              [&vec](auto lhs, auto rhs) { return vec[lhs] < vec[rhs]; });
    return indices;
};


int main() {
    int N, T;
    std::cin >> N >> T;

    std::vector<int> tmpA(N), tmpB(N);
    for (int i = 0; i < N; i++) {
        std::cin >> tmpA[i] >> tmpB[i];
    }

    auto indices = index_sort(tmpA);
    std::vector<int> A(N), B(N);
    for (int i = 0; i < N; i++) {
        A[i] = tmpA[indices[i]];
        B[i] = tmpB[indices[i]];
    }

    std::vector<int> dp(T + 1, 0);
    int max = 0;
    for (int i = 0; i < N; i++) {
        for (int t = T - 1; t >= 1; t--) {
            if (dp[t] == 0) {
                continue;
            }
            int idx = std::min(T, t + A[i]);
            dp[idx] = std::max(dp[idx], dp[t] + B[i]);
            max = std::max(dp[idx], max);
        }
        int idx = std::min(T, A[i]);
        dp[idx] = std::max(dp[idx], B[i]);
        max = std::max(dp[idx], max);
    }

    std::cout << max << std::endl;
}
