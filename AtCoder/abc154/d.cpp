#include <bits/stdc++.h>


int main() {
    long long int N, K;
    std::cin >> N >> K;

    std::queue<long long int> que;
    long long int sum = 0, max = 0;
    for (int i = 0; i < N; i++) {
        int p;
        std::cin >> p;
        if (que.size() == K) {
            sum -= que.front();
            que.pop();
        }
        sum += p;
        que.push(p);
        if (que.size() == K) {
            max = std::max(sum, max);
        }
    }

    std::cout << std::fixed << std::setprecision(10) << (max + K) / 2.0 << std::endl;
}
