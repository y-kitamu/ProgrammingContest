#include <bits/stdc++.h>


template <class Comp>
std::vector<int> index_sort(std::vector<int>& vec, Comp compare) {
    std::vector<int> idx(vec.size());
    std::iota(idx.begin(), idx.end(), 0);
    std::sort(idx.begin(), idx.end(),
              [&vec, &compare](auto& lhs, auto& rhs) { return compare(vec[lhs], vec[rhs]); });
    return idx;
}


int main() {
    int N;
    std::cin >> N;
    std::vector<int> A(N), B(N);
    std::vector<int> count_a(N, 0), count_b(N, 0), cnt(N, 0);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
        count_a[A[i] - 1]++;
        cnt[A[i] - 1]++;
    }
    for (int i = 0; i < N; i++) {
        std::cin >> B[i];
        count_b[B[i] - 1]++;
        cnt[B[i] - 1]++;
    }

    int max = 0;
    for (int i = 0; i < N; i++) {
        max = std::max(count_a[i] + count_b[i], max);
    }
    if (max > N) {
        std::cout << "No" << std::endl;
        return 0;
    }

    auto cnt_idx = index_sort(cnt, std::greater<int>());

    std::vector<int> ra(N), rb(N);
    int ia = 0, ib = N - 1;
    bool flag = false;
    for (int i = 0; i < N; i++) {
        auto idx = cnt_idx[i];
        for (int j = 0; j < count_a[idx]; j++) {
            ra[ia++] = idx;
        }
        for (int j = 0; j < count_b[idx]; j++) {
            if (!flag && ia > ib) {
                ib = 0;
                flag = true;
            }
            rb[ib] = idx + 1;
            if (flag) {
                ib++;
            } else {
                ib--;
            }
        }
    }

    auto indices = index_sort(ra, std::less<int>());
    std::vector<int> res(N);
    for (int i = 0; i < N; i++) {
        res[i] = rb[indices[i]];
    }

    std::cout << "Yes" << std::endl;
    for (int i = 0; i < N; i++) {
        std::cout << res[i];
        if (i < N - 1) {
            std::cout << " ";
        }
    }
    std::cout << std::endl;
}
