#include <bits/stdc++.h>

int main() {
    int N;
    std::cin >> N;

    std::vector<std::vector<int>> D(N + 1, std::vector<int>(N + 1, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cin >> D[i + 1][j + 1];
            D[i + 1][j + 1] += D[i + 1][j] + D[i][j + 1] - D[i][j];
        }
    }

    auto search_max = [&D, &N] (int width, int height) {
        int max = 0;
        for (int i = 0; i <= N - height; i++) {
            for (int j = 0; j <= N - width; j++) {
                int val = D[i + height][j + width] - D[i + height][j] - D[i][j + width] + D[i][j];
                max = std::max(val, max);
            }
        }
        return max;
    };

    std::vector<int> maxes(N * N, 0);
    for (int i = 1; i <= N * N; i++) {
        for (int j = 1; j <= std::sqrt(i); j++) {
            if (i % j == 0) {
                int val = std::max(search_max(j, i / j), search_max(i / j, j));
                maxes[i - 1] = std::max(maxes[i - 1], val);
            }
        }
        if (i > 1) {
            maxes[i - 1] = std::max(maxes[i - 1], maxes[i - 2]);
        }
    }

    int Q;
    std::cin >> Q;
    std::vector<int> qs(Q);
    for (int i = 0; i < Q; i++) {
        std::cin >> qs[i];
    }

    for (int i = 0; i < Q; i++) {
        std::cout << maxes[qs[i] - 1] << std::endl;
    }
}
