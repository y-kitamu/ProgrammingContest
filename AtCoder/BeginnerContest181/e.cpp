#include <bits/stdc++.h>


int main() {
    int N, M;
    std::cin >> N >> M;

    std::vector<long long int> heights(N);
    for (int i = 0; i < N; i++) {
        std::cin >> heights[i];
    }
    std::sort(heights.begin(), heights.end());

    std::vector<long long int> W(M);
    for (int i = 0; i < M; i++) {
        std::cin >> W[i];
    }
    std::sort(W.begin(), W.end());

    long long int MAX = 2e9;
    long long int w_used_min = MAX;
    long long int w_no_min = 0;
    long long int w_idx = 0;
    for (int i = 0; i < N; i += 2) {
        long long int tmp_min = MAX;
        if (i > 0 && w_used_min != MAX) {
            // W already used
            tmp_min = w_used_min + heights[i] - heights[i - 1];
        }
        while (w_idx < M && W[w_idx] <= heights[i]) {
            // W used here
            tmp_min = std::min(tmp_min, w_no_min + heights[i] - W[w_idx]);
            w_idx++;
        }
        if (w_idx < M) {
            w_used_min = std::min(tmp_min, w_no_min + W[w_idx] - heights[i]);
        } else {
            w_used_min = std::min(tmp_min, w_no_min + heights[i] - W[M - 1]);
        }

        if (i < N - 1) {
            // W not used
            w_no_min += heights[i + 1] - heights[i];
        }
    }
    std::cout << w_used_min << std::endl;
}
