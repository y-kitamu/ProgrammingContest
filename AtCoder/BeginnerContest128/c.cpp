#include <bits/stdc++.h>

int N, M;
std::vector<int> p;


int calc_sum(std::vector<int> status) {
    for (int i = 0; i < M; i++) {
        if (status[i] % 2 != p[i]) {
            return 0;
        }
    }
    return 1;
}

std::vector<int> update_status(std::vector<int> status, std::vector<int> swit) {
    for (int i = 0; i < M; i++) {
        status[i] += swit[i];
    }
    return status;
}


int search(int idx, std::vector<int> status, std::vector<std::vector<int>> &switches) {
    if (idx == N) {
        return calc_sum(status);
    }

    int sum = search(idx + 1, status, switches);
    std::vector<int> switch_on = update_status(status, switches[idx]);
    sum += search(idx + 1, switch_on, switches);
    return sum;
}


int main() {
    std::cin >> N >> M;

    std::vector<std::vector<int>> switches(N, std::vector<int>(M, 0));
    for (int i = 0; i < M; i++) {
        int k;
        std::cin >> k;
        for (int j = 0; j < k; j++) {
            int s;
            std::cin >> s;
            switches[s - 1][i] = 1;
        }
    }
    p = std::vector<int>(M);
    for (int i = 0; i < M; i++) {
        std::cin >> p[i];
    }

    std::vector<int> status(M, 0);
    int sum = search(0, status, switches);
    std::cout << sum << std::endl;
}
