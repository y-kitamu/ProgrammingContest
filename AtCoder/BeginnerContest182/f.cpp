#include <bits/stdc++.h>


int calc_step(int idx, long long int X, std::vector<long long int>& A) {
    if (idx == 0) {
        if (std::abs(X) >= A[1]) {
            return 0;
        }
        return 1;
    }
    int cnt = 0;
    long long int max = A[idx + 1] / A[idx];
    if (X < 0) {
        for (long long int i = 0; i < max; i++) {
            long long int val = X + A[idx] * i;
            if (std::abs(val) < A[idx]) {
                cnt += calc_step(idx - 1, val, A);
            }
        }
    }
    if (X > 0) {
        for (int i = 0; i < max; i++) {
            long long int val = X - A[idx] * i;
            if (std::abs(val) < A[idx]) {
                cnt += calc_step(idx - 1, val, A);
            }
        }
    }
    if (X == 0) {
        for (int i = 0; i < max; i++) {
            long long int val = X + A[idx] * i;
            if (std::abs(val) < A[idx]) {
                cnt += calc_step(idx - 1, val, A);
            }
        }
        for (int i = 0; i < max; i++) {
            long long int val = X - A[idx] * i;
            if (std::abs(val) < A[idx]) {
                cnt += calc_step(idx - 1, val, A);
            }
        }
    }
    return cnt;
}


int main() {
    long long int N, X;
    std::cin >> N >> X;
    std::vector<long long int> A(N);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    int cnt = 0;
    for (int i = 0; i <= X / A[N - 1] + 1; i++) {
        cnt += calc_step(N - 2, X - A[N - 1] * i, A);
    }
    std::cout << cnt << std::endl;
}
