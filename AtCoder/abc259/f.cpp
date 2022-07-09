/**
 * @file f.cpp
 * @brief
 * @author Yusuke Kitamura <ymyk6602@gmail.com>
 * @date 2022-07-09 22:23:45
 */
#include <bits/stdc++.h>


struct Edge {
    int n1, n2, w;
};


std::vector<int> solve(int idx, int pidx, int w, std::vector<int>& d,
                       std::vector<std::vector<Edge>>& ll) {
    auto comp = [](auto& lhs, auto& rhs) { return lhs.second < rhs.second; };
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(comp)> pq{comp};
    for (int i = 0; i < ll[idx].size(); i++) {
        auto next = ll[idx][i];
        if (next.n1 == pidx || next.n2 == pidx) {
            continue;
        }
        auto ni = next.n1 == idx ? next.n2 : next.n1;
        auto res = solve(ni, idx, next.w, d, ll);
        pq.push(std::make_pair(0, res[0]));
        pq.push(std::make_pair(1, res[1]));
    }

    int cnt = 0;
    int sum0 = 0, sum1 = 0;
    while (!pq.empty()) {
        auto top = pq.top();
        cnt += top.first;
        if (cnt < w) {
            sum0 += top.second;
            sum1 += top.second;
        } else if (cnt == w) {
        }
    }
    return {sum0, sum1 + w};
}

int main() {
    int N;
    std::cin >> N;

    std::vector<int> d(N);
    for (int i = 0; i < N; i++) {
        std::cin >> d[i];
    }

    std::vector<std::vector<Edge>> ll(N);
    for (int i = 0; i < N - 1; i++) {
        int n1, n2, w;
        std::cin >> n1 >> n2 >> w;
        n1--, n2--;
        ll[n1].push_back({n1, n2, w});
        ll[n2].push_back({n1, n2, w});
    }

    auto res = solve(0, -1, 0, d, ll);
    std::cout << std::max(res[0], res[1]) << std::endl;
}
