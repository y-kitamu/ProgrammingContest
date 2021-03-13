#include <bits/stdc++.h>

template <class Comp>
std::vector<int> index_sort(std::vector<int>& vec, Comp compare = std::greater<int>()) {
    std::vector<int> idx(vec.size());
    std::iota(idx.begin(), idx.end(), 0);

    std::sort(idx.begin(), idx.end(),
              [&vec, &compare](int lhs, int rhs) { return compare(vec[lhs], vec[rhs]); });
    return idx;
}


int main() {
    int N, M, Q;
    std::cin >> N >> M >> Q;

    std::vector<int> W(N), V(N);
    for (int i = 0; i < N; i++) {
        std::cin >> W[i] >> V[i];
    }

    auto sort_idx = index_sort(V, std::greater<int>());

    std::vector<int> X(M);
    for (int i = 0; i < M; i++) {
        std::cin >> X[i];
    }

    for (int i = 0; i < Q; i++) {
        int R, L;
        std::cin >> R >> L;
        R--, L--;

        std::vector<int> avail;
        for (int i = 0; i < M; i++) {
            if (i < R || L < i) {
                avail.emplace_back(X[i]);
            }
        }
        std::sort(avail.begin(), avail.end());

        int sum = 0;
        for (int i = 0; i < N; i++) {
            int box = sort_idx[i];
            auto itr = std::lower_bound(avail.begin(), avail.end(), W[box]);
            if (itr != avail.end()) {
                sum += V[box];
                avail.erase(itr);
            }
        }
        std::cout << sum << std::endl;
    }
}
