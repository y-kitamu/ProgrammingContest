#include <bits/stdc++.h>


struct Work {
    Work(int point, int start, int end): point(point), start(start), end(end) {}
    int point;
    int start, end;
};


int binary_search(int value, int left, int right, const std::vector<int>& vec) {
    if (left == right) {
        return left;
    }
    int mid = (left + right) / 2;
    if (value == vec[mid]) {
        return mid;
    }
    if (value < vec[mid]) {
        return binary_search(value, left, mid, vec);
    }
    return binary_search(value, mid + 1, right, vec);
}


int main() {
    int N, Q;
    std::cin >> N >> Q;

    std::vector<Work> works;
    for (int i = 0; i < N; i++) {
        int S, T, X;
        std::cin >> S >> T >> X;
        works.emplace_back(Work(X, S, T));
    }
    std::sort(works.begin(), works.end(), [] (auto &lhs, auto &rhs) { return lhs.point > rhs.point; });

    std::vector<int> qs(Q);
    for (int i = 0; i < Q; i++) {
        std::cin >> qs[i];
    }

    std::vector<int> pred(Q, -1);
    for (auto work : works) {
        int min = work.start - work.point;
        int max = work.end - work.point - 1;
        int min_idx = binary_search(min, 0, Q, qs);
        int max_idx = binary_search(max, 0, Q, qs);
        if (qs[min_idx] < min) {
            min_idx++;
        }
        if (max_idx == Q || qs[max_idx] > max) {
            max_idx--;
        }
        // pred[min_idx] = work.point;
        // pred[max_idx] = work.point;
        for (int i = min_idx; i <= max_idx; i++) {
            pred[i] = work.point;
        }
    }

    for (int i = 0; i < Q; i++) {
        std::cout << pred[i] << std::endl;
    }
}
