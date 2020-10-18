#include <bits/stdc++.h>


int main() {
    int N, M;
    std::cin >> N >> M;

    std::vector<int> weights(N);
    for (int i = 0; i < N; i++) {
        std::cin >> weights[i];
    }

    std::vector<std::pair<int, int>> parts(M);
    int min_v = 1e8;
    for (int i = 0; i < M; i++) {
        int l, v;
        std::cin >> l >> v;
        parts[i] = std::make_pair(l, v);
        min_v = std::min(min_v, v);
    }
    std::sort(weights.begin(), weights.end(), [] (auto &lhs, auto &rhs) {return lhs < rhs;});

    if (weights[N - 1] > min_v) {
        std::cout << -1 << std::endl;
        return 0;
    }

    std::sort(parts.begin(), parts.end(), [] (auto& lhs, auto &rhs) { return lhs.first < rhs.first;});

    int min_dist = 1e8 * 8;
    do {
        std::vector<int> distances(N - 1, 0);
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N - 1; j++) {
                int w = parts[i].second - weights[j];
                int l = parts[i].first;
                for (int k = j; k < N - 1; k++) {
                    l -= distances[k];
                    w -= weights[k + 1];
                    if (l <= 0) {
                        break;
                    }
                    if (w < 0) {
                        distances[k] += l;
                        break;
                    }
                }
            }
        }

        int dist = 0;
        for (int i = 0; i < N - 1; i++) {
            dist += distances[i];
        }
        min_dist = std::min(dist, min_dist);
    } while (std::next_permutation(weights.begin(), weights.end() - 1));

    std::cout << min_dist << std::endl;
}
