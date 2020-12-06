#include <bits/stdc++.h>


int main() {
    long long int N, K;
    std::cin >> N >> K;

    std::vector<long long int> A(N);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    long long int count = 0;
    long long int sum = 0;
    long long int lhs = 0, rhs = 0;
    for (;lhs < N; lhs++) {
        for (; rhs < N; rhs++) {
            if (sum >= K) {
                break;
            }
            sum += A[rhs];
        }
        if (sum < K) {
            break;
        }
        count += N - rhs + 1ll;
        sum -= A[lhs];
    }

    std::cout << count << std::endl;
}
