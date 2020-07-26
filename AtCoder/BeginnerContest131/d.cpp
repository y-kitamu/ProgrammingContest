#include <bits/stdc++.h>


int main() {
    int N;
    std::cin >> N;

    std::vector<std::vector<int>> jobs(N, std::vector<int>(2));
    for (int i = 0; i < N; i++) {
        std::cin >> jobs[i][0] >> jobs[i][1];
    }
    std::sort(jobs.begin(), jobs.end(), [](auto &lhs, auto &rhs) { return lhs[1] < rhs[1]; });

    int cost_time = 0;
    for (auto&& job : jobs) {
        cost_time += job[0];
        if (cost_time > job[1]) {
            std::cout << "No" << std::endl;
            return 0;
        }
    }
    std::cout << "Yes" << std::endl;
}
