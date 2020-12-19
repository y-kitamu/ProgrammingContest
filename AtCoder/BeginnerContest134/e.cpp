#include <bits/stdc++.h>


struct Node {
    int val, count = 0;
};


int binarySearch(int val, int left, int right, const std::vector<int>& vec) {
    int mid = (left + right) / 2;
    if (vec[mid] == val) {
        return mid;
    }
    if (val < vec[mid]) {
        return binarySearch(val, left, mid, vec);
    }
    return binarySearch(val, mid + 1, right, vec);
}


int main() {
    int N;
    std::cin >> N;
    std::vector<int> a(N);
    for (int i = 0; i < N; i++) {
        std::cin >> a[i];
    }

    std::vector<int> a_sorted(N);
    std::partial_sort_copy(a.begin(), a.end(), a_sorted.begin(), a_sorted.end());
    std::vector<Node> seg(N * 2 - 1);

    for (int i = 0; i < N; i++) {
        int idx = binarySearch(a[i], 0, N, a_sorted);
        // seg[N - 1 + idx] = Node()
    }
}
