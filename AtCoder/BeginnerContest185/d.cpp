#include <bits/stdc++.h>



int main() {
    long long int N, M;
    std::cin >> N >> M;

    std::vector<int> blue(M + 2, 0);
    for (int i = 1; i <= M; i++) {
        std::cin >> blue[i];
    }
    blue[M + 1] = N + 1;
    std::sort(blue.begin(), blue.end(), [] (auto lhs, auto rhs) { return lhs < rhs; });

    std::vector<long long int> diffs;
    int min = N;
    for (int i = 1; i <= M + 1; i++) {
        int diff = blue[i] - blue[i - 1] - 1;
        if (diff > 0) {
            diffs.emplace_back(diff);
            min = std::min(diff, min);
        }
    }

    long long int sum = 0;
    for (auto diff : diffs) {
        sum += diff / min;
        if (diff % min != 0) {
            sum++;
        }
    }
    std::cout << sum << std::endl;
}
