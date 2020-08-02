#include <bits/stdc++.h>


int main() {
    int N, K;
    std::cin >> N >> K;

    std::vector<int> A(N);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<int> length = A;
    std::vector<int> split(N, 1);

    auto compare = [](std::pair<int, double> lhs, std::pair<int, double> rhs) {
        return lhs.second < rhs.second;
    };
    std::priority_queue<std::pair<int, double>, std::vector<std::pair<int, double>>, decltype(compare)> que {compare};

    for (int i = 0; i < N; i++) {
        que.push(std::make_pair(i, length[i]));
    }

    int count = K;
    while (count > 0) {
        auto q = que.top();
        que.pop();
        count--;
        split[q.first]++;
        length[q.first] = (A[q.first] + split[q.first] - 1) / split[q.first];
        que.push(std::make_pair(q.first, length[q.first]));
    }
    auto q = que.top();
    std::cout << length[q.first] << std::endl;
}
