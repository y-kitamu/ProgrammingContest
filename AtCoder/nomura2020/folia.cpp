#include <bits/stdc++.h>


int main() {
    int N;
    std::cin >> N;

    std::vector<int> A(N + 1);
    std::cin >> A[0];
    if (A[0] == 1) {
        if (N == 0) {
            std::cout << 1 << std::endl;
        } else {
            std::cout << -1 << std::endl;
        }
        return 0;
    } else if (A[0] > 1) {
        std::cout << -1 << std::endl;
        return 0;
    }
    for (int i = 1; i < N + 1; i++) {
        std::cin >> A[i];
    }

    std::vector<long long int> pow2(45, 1);
    for (int i = 1; i < 45; i++) {
        pow2[i] = pow2[i - 1] * 2;
    }

    int node = 0;
    long long int sum = 0;
    long long int n_sub = 0;
    std::vector<int> n_two(45, 0);
    for (int i = N; i >= 0; i--) {
        if (i > 0) {
            node = (node + A[i] + 1) / 2;
        }
        n_sub += A[i];
        sum += n_sub;
        if (i < 45 && n_sub > pow2[i]) {
            int ext = n_sub - pow2[i];
            int factor = 1;
            for (int j = i; j < 45; j++) {
                int margin = pow2[j] - n_two[j] - A[j];
                if (margin <= 0) {
                    factor *= 2;
                }
                sum -= factor * ext;
                if (margin >= ext) {
                    n_two[j] += ext;
                    break;
                }
                n_two[j] += margin;
                if (margin > 0) {
                    ext -= margin;
                }
            }
            n_sub = pow2[i];
        }
    }
    if (node != 1) {
        std::cout << -1 << std::endl;
        return 0;
    }
    std::cout << sum << std::endl;
}
