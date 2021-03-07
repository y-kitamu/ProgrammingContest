#include <bits/stdc++.h>


int main() {
    int N, M;
    std::cin >> N >> M;

    std::vector<std::vector<int>> linked_list(N);
    for (int i = 0; i < M; i++) {
        int s, t;
        std::cin >> s >> t;
        s--, t--;
        linked_list[s].emplace_back(t);
    }

    std::vector<double> P(N, 0.0);
    P[0] = 1.0;
    for (int i = 0; i < N; i++) {
        int num = linked_list[i].size();
        for (auto next : linked_list[i]) {
            P[next] += P[i] * (double)1.0 / num;
        }
    }

    std::vector<double> E(N, 0.0);
    for (int i = N - 2; i >= 0; i--) {
        double e = 0.0;
        for (auto& val : linked_list[i]) {
            e += E[val] + 1.0;
        }
        E[i] = e / linked_list[i].size();
    }

    double max_diff = 0.0;
    for (int i = 0; i < N - 1; i++) {
        if (linked_list[i].size() <= 1) {
            continue;
        }
        double sum = 0;
        for (auto& idx : linked_list[i]) {
            sum += E[idx];
        }
        sum += linked_list[i].size() - 1;
        for (auto& idx : linked_list[i]) {
            double e = (sum - E[idx]) / (linked_list[i].size() - 1.0);
            max_diff = std::max((E[i] - e) * P[i], max_diff);
        }
    }

    std::cout << std::fixed << std::setprecision(10) << E[0] - max_diff << std::endl;
}
