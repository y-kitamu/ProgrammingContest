#include <bits/stdc++.h>


int main() {
    int N;
    std::cin >> N;
    std::vector<std::pair<int, int>> A(N);
    for (int i = 0; i < N; i++) {
        int val;
        std::cin >> val;
        A[i] = std::make_pair(i, val);
    }
    std::sort(A.begin(), A.end(), [](auto lhs, auto rhs) {return lhs.second > rhs.second;});

    auto max = A[0];
    for (int i = 0; i < N; i++) {
        if (max.first == i) {
            std::cout << A[1].second << std::endl;
        } else {
            std::cout << max.second << std::endl;
        }
    }
}
