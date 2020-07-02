#include <bits/stdc++.h>


int main() {
    int N, M, K;
    std::cin >> N >> M >> K;

    std::vector<long long int> A(N + 1, 0), B(M + 1, 0);
    for (int i = 1; i <= N; i++) {
        std::cin >> A[i];
        A[i] += A[i - 1];
    }
    for (int j = 1; j <= M; j++) {
        std::cin >> B[j];
        B[j] += B[j - 1];
    }


    int i_a = 0;
    for (; i_a <= N; i_a++) {
        if (A[i_a] > K) {
            break;
        }
    }
    i_a = std::min(i_a, N);

    int i_b = 0;
    int max_count = 0;
    for (; i_a >= 0; i_a--) {
        int val = K - A[i_a];
        for (; i_b <= M; i_b++) {
            if (B[i_b] > val) {
                break;
            }
        }
        max_count = std::max(i_a + i_b - 1, max_count);
    }

    std::cout << max_count << std::endl;
}
