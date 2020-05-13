#include <iostream>
#include <vector>

int N, M, X;
std::vector<int> cost;
std::vector<std::vector<int>> vals;
static constexpr int MAX = 10000000;

int all_search(int idx, int sum, std::vector<int> idx_list) {
    if (idx == N) {
        for (int j = 0; j < M; j++) {
            int is_avail = 0;
            for (auto i : idx_list) {
                is_avail += vals[i][j];
            }
            if (is_avail < X) {
                return MAX;
            }
        }
        return sum;
    }

    int val1 = all_search(idx + 1, sum, idx_list);
    idx_list.push_back(idx);
    int val0 = all_search(idx + 1, sum + cost[idx], idx_list);
    return std::min(val0, val1);
}


int main() {
    std::cin >> N >> M >> X;

    cost = std::vector<int>(N);
    vals = std::vector<std::vector<int>>(N, std::vector<int>(M));

    for (int i = 0; i < N; i++) {
        std::cin >> cost[i];
        for (int j = 0; j < M; j++) {
            std::cin >> vals[i][j];
        }
    }

    std::vector<int> idx_list;
    int min_cost = all_search(0, 0, idx_list);
    if (min_cost == MAX) {
        std::cout << -1 << std::endl;
    } else {
        std::cout << min_cost << std::endl;
    }
}
