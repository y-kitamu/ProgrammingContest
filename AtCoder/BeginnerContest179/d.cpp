#include <bits/stdc++.h>


long long int MOD = 998244353;

long long int naiveSolution(std::vector<std::pair<int, int>> sections, int N) {
    std::vector<long long int> counts(N, 0);
    counts[0] = 1;
    for (int i = 0; i < N; i++) {
        for (auto section : sections) {
            for (int j = section.first; j <= section.second; j++) {
                if (i + j < N) {
                    counts[i + j] += counts[i];
                    if (counts[i + j] > MOD) {
                        counts[i + j] = counts[i + j] % MOD;
                    }
                }
            }
        }
    }
    return counts[N - 1];
}


long long int solution(std::vector<std::pair<int, int>> sections, int N) {
    int delta = 0;
    for (auto section : sections) {
        delta += section.second - section.first;
    }
    std::vector<int> counts(N, 0);
    counts[0] = 1;
    for (int i = 0; i < N; i++) {
        for (auto section: sections) {
            if (i + section.first < N) {
                counts[i + section.first] += counts[i];
            }
            if (counts[i + section.first] > MOD) {
                counts[i + section.first] = counts[i + section.first] % MOD;
            }
        }
    }
};


void test_big() {
    int N = 2 * 1e5;
    int K = 10;

    std::vector<std::pair<int, int>> sections(K);
    for (int i = 0; i < K; i++) {
        sections[i].first = N / K * i + 1;
        sections[i].second = N / K * (i + 1);
    }

    std::cout << naiveSolution(sections, N) << std::endl;
}


int main() {
    int N, K;
    std::cin >> N >> K;
    std::vector<std::pair<int, int>> sections(K);
    for (int i = 0; i < K; i++) {
        std::cin >> sections[i].first >> sections[i].second;
    }
    std::cout << solution(sections, N) << std::endl;
    // test_big();
}
