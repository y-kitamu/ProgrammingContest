#include <bits/stdc++.h>


std::vector<int> get_divisors(int N) {
    std::vector<int> divisors;
    for (int i = 1; i <= std::sqrt(N); i++) {
        if (N % i == 0) {
            divisors.emplace_back(i);
            if (N / i != N % i) {
                divisors.emplace_back(N / i);
            }
        }
    }
    return divisors;
}


int main() {
    int N, K;
    std::cin >> N >> K;

    std::vector<int> A(N);
    int sum = 0;
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
        sum += A[i];
    }

    int max = 1;
    std::vector<int> divisors = get_divisors(sum);
    for (auto div : divisors) {
        int count = 0;
        for (int i = 0; i < N - 1; i++) {
            int d = A[i] % div;
            if (d < 0) {
                d += div;
            }
            if (d > div / 2) {
                int cnt = div - d;
                A[i + 1] -= cnt;
                count += cnt;
            } else {
                A[i + 1] += d;
                count += d;
            }
        }
        // std::cout << "div = " << div << " , " << "count = " << count << std::endl;
        if (count <= K) {
            max = std::max(max, div);
        }
    }
    std::cout << max << std::endl;
}
