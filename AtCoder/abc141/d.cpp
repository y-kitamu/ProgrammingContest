#include <bits/stdc++.h>


int main() {
    long long int N, M;
    std::cin >> N >> M;

    std::vector<long long int> a(N);
    for (int i = 0; i < N; i++) {
        std::cin >> a[i];
    }

    std::priority_queue<long long int> que;
    for (auto val : a) {
        que.push(val);
    }

    for (int i = 0; i < M; i++) {
        auto top = que.top();
        que.pop();
        que.push(top / 2);
    }

    long long int sum = 0;
    while (!que.empty()) {
        sum += que.top();
        que.pop();
    }

    std::cout << sum << std::endl;
}
