#include <iostream>


int main() {
    long N, K;

    std::cin >> N >> K;

    long A[N], maxval = 0;
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
        if (maxval < A[i]) maxval = A[i];
    }

    long answer = 0;
    long cur = 0;

    for (int i = 60; i >= 0; i--) {
        long val = 1LL << i;
        if (val > K && val > maxval) continue;
        // std::cout << "K = " << K << ", maxval = " << maxval << ", val = " << val << std::endl;

        int zeros = 0;
        for (int i = 0; i < N; i++) {
            if ((val & A[i]) == 0) {
                zeros++;
            }
        }
        int ones = N - zeros;

        if (cur + val <= K) {
            if (zeros > ones) {
                answer += zeros * val;
                cur += val;
            } else {
                answer += ones * val;
            }
        } else {
            answer += ones * val;
        }
    }

    std::cout << answer << std::endl;
}
