#include <bits/stdc++.h>


int binarySearch(int val, int left, int right, const std::vector<int>& vec) {
    if (left == right) {
        return left;
    }
    int mid = (left + right) / 2;
    if (val >= vec[mid]) {
        return binarySearch(val, left, mid, vec);
    }
    return binarySearch(val, mid + 1, right, vec);
}


int main() {
    int N, M;
    std::cin >> N >> M;

    std::vector<std::pair<int, int>> sv(N);
    for (int i = 0; i < N; i++) {
        std::cin >> sv[i].first >> sv[i].second;
    }
    std::sort(sv.begin(), sv.end(), [] (auto &lhs, auto &rhs) { return lhs.first > rhs.first; });

    std::vector<int> values(N);
    for (int i = 0; i < N; i++) {
        values[i] = sv[i].second;
    }
    std::sort(values.begin(), values.end(), [](auto &lhs, auto &rhs) { return lhs > rhs; });

    int idx = M;
    int sum = 0;
    for (int i = 0; i < N; i++) {
        auto pair = sv[i];
        if (pair.first > idx) {
            continue;
        }
        int order_idx = binarySearch(pair.second, 0, values.size() - 1, values);
        if (order_idx < idx) {
            sum += pair.second;
            values.erase(values.begin() + order_idx);
            idx--;
        }
    }
    std::cout << sum << std::endl;
}
