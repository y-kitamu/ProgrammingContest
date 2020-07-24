#include <bits/stdc++.h>

int N, M;
int MOD = 1000000007;
std::vector<int> counts;
std::vector<int> as;

int count(int idx) {
    if (idx == N) {
        return 1;
    }
    if (counts[idx] != -1) {
        return counts[idx];
    }
    int cnt = 0;
    if (as[idx + 1] == 0) {
        cnt += count(idx + 1);
    }
    if (idx + 2 <= N && as[idx + 2] == 0) {
        cnt += count(idx + 2);
    }
    counts[idx] = cnt % MOD;
    return counts[idx];
}


int main() {
    std::cin >> N >> M;

    as = std::vector<int>(N + 1, 0);
    for (int i = 0; i < M; i++) {
        int idx;
        std::cin >> idx;
        as[idx] = 1;
    }

    counts = std::vector<int>(N, -1);

    int sum = count(0);
    std::cout << sum << std::endl;
}
