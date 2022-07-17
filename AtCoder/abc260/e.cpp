/**
 * @file e.cpp
 * @brief
 * @author Yusuke Kitamura <ymyk6602@gmail.com>
 * @date 2022-07-17 21:48:13
 */
#include <bits/stdc++.h>


int main() {
    int N, M;
    std::cin >> N >> M;

    std::vector<int> A(N), B(N);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i] >> B[i];
    }

    std::vector<int> ia(N);
    std::iota(ia.begin(), ia.end(), 0);
    std::sort(ia.begin(), ia.end(), [&A](int lhs, int rhs) { return A[lhs] < A[rhs]; });

    int cnt = N;
    int lval = A[ia[0]];
    int rval = A[ia[N - 1]];
}
