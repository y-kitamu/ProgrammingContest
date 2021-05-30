#include <bits/stdc++.h>

std::vector<int> index_sort(std::vector<long long int>& vec) {
    std::vector<int> idx(vec.size());
    std::iota(idx.begin(), idx.end(), 0);
    std::sort(idx.begin(), idx.end(), [&vec](auto& lhs, auto& rhs) { return vec[lhs] < vec[rhs]; });
    return idx;
}


int main() {
    long long int N, K;

    std::cin >> N >> K;
    // K = 10000000;
    // N = 100000;
    std::vector<long long int> a(N), b(N);
    for (int i = 0; i < N; i++) {
        std::cin >> a[i] >> b[i];
    }

    auto sorted_idx = index_sort(a);
    std::vector<long long int> sa(N), sb(N);
    for (int i = 0; i < N; i++) {
        sa[i] = a[sorted_idx[i]];
        sb[i] = b[sorted_idx[i]];
    }

    long long int cur = 0;

    for (int i = 0; i < N; i++) {
        long long int cp = sa[i];
        if (cur + K < cp) {
            break;
        }
        K += sb[i] - (cp - cur);
        cur = cp;
    }
    if (K >= 0) {
        cur += K;
    }
    std::cout << cur << std::endl;
}
