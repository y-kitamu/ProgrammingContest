#include <bits/stdc++.h>

struct Match {
    Match() {}
    std::vector<Match*> prev_matches;
    std::vector<Match*> next_matches;
};

std::pair<int, int> get_pair(int a, int b) {
    int max_idx = std::max(a, b);
    int min_idx = std::min(a, b);
    auto pair = std::make_pair(min_idx, max_idx);
    return pair;
}

int main() {
    int N;
    std::cin >> N;
    std::map<std::pair<int, int>, Match> matches;
    std::vector<std::vector<int>> oppos(N, std::vector<int>(N - 1));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N - 1; j++) {
            int opp;
            std::cin >> opp;
            opp--;
            oppos[i][j] = opp;
        }
    }

    std::vector<Match*> starts;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N - 1; j++) {
            auto pair = get_pair(i, oppos[i][j]);
            if (matches.find(pair) == matches.end()) {
                matches[pair] = Match();
                starts.emplace_back(&matches[pair]);
            }
            if (j > 0) {
                auto prev_pair = get_pair(i, oppos[i][j - 1]);
                matches[pair].prev_matches.emplace_back(&matches[prev_pair]);
            }
            if (j < N - 2) {
p                auto next_pair = get_pair(i, oppos[i][j + 1]);
                matches[pair].next_matches.emplace_back(&matches[next_pair]);
            }
        }
    }

    int max_loop = N * (N - 1) / 2;
    int max = 0;
    for (auto start : starts) {
        int tmp_max = 0;
        std::queue<std::pair<Match*, int>> que;
        que.push(std::make_pair(start, 1));
        while (!que.empty()) {
            auto top = que.front();
            que.pop();
            tmp_max = top.second;
            if (tmp_max > max_loop) {
                tmp_max = -1;
                break;
            }
            for (auto next : top.first->next_matches) {
                que.push(std::make_pair(next, top.second + 1));
            }
        }
        if (tmp_max == -1) {
            max = -1;
            break;
        }
        max = std::max(tmp_max, max);
    }
    std::cout << max << std::endl;
}
