#include <bits/stdc++.h>


int main() {
    int N, K;
    std::cin >> N >> K;

    std::vector<long long int> A(N), sum(N + 1, 0);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
        sum[i + 1] = sum[i] + A[i];
    }

    std::map<long long int, std::vector<long long int>> cnts;
    for (long long int i = 0; i <= N; i++) {
        sum[i] = (sum[i] - i) % K;
        if (sum[i] < 0) {
            sum[i] += K;
        }
        cnts[sum[i]].emplace_back(i);
    }

    long long int cnt = 0;
    for (auto& pair : cnts) {
        auto indices = pair.second;
        long long int lhs = 0;
        for (long long int i = 1; i < indices.size(); i++) {
            while (i > lhs && indices[i] - indices[lhs] >= K) {
                lhs++;
            }
            cnt += i - lhs;
        }
    }

    std::cout << cnt << std::endl;
}
