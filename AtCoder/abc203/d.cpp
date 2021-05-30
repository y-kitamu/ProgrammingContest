#include <bits/stdc++.h>


int main() {
    int N, K;
    std::cin >> N >> K;

    std::vector<std::vector<int>> map(N, std::vector<int>(N));
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            std::cin >> map[y][x];
        }
    }

    int center = K * K / 2 + 1;
    if (K % 2 == 0) {
        center--;
    }
    int min = 0, max = 1e9;
    while (min != max) {
        int mid = (min + max) / 2;
        // std::cout << mid << std::endl;
        std::vector<std::vector<int>> cum(N + 1, std::vector<int>(N + 1, 0));
        for (int y = 1; y <= N; y++) {
            for (int x = 1; x <= N; x++) {
                if (map[y - 1][x - 1] <= mid) {
                    cum[y][x]++;
                }
                cum[y][x] += cum[y][x - 1] + cum[y - 1][x] - cum[y - 1][x - 1];
                // std::cout << cum[y][x] << " ";
            }
            // std::cout << std::endl;
        }

        int max_cnt = 0;
        for (int y = 0; y <= N - K; y++) {
            for (int x = 0; x <= N - K; x++) {
                max_cnt =
                    std::max(cum[y + K][x + K] - cum[y + K][x] - cum[y][x + K] + cum[y][x], max_cnt);
            }
        }

        if (max_cnt < center) {
            min = mid + 1;
        } else {
            max = mid;
        }
    }

    std::cout << min << std::endl;
}
