#include <bits/stdc++.h>


int main() {
    long long int MAX = 1000000007;
    int T;
    std::cin >> T;
    for (int t = 0; t < T; t++) {
        long long int N, A, B;
        std::cin >> N >> A >> B;
        if (A > B) {
            std::swap(A, B);
        }
        long long int all = (N - A + 1) * (N - B + 1) % MAX;
        all = all * all % MAX;
        long long int inner = (B - A + 1) * (N - B + 1) % MAX;
        inner = inner * inner % MAX;

        long long int inter = 0;
        if (A > 1 && B + 1 <= N) {
            long long int mint = std::min(N, A + B - 1);
            mint = (mint + B + 1) * (mint - B) / 2 % MAX;
            long long int tmp = (N - mint + 1) * 2 % MAX;
            inter = tmp * tmp % MAX;
            inter = (inter + (N - B + 1) * tmp * 2 % MAX) % MAX;
        }

        long long int res = (all - inter - inner) % MAX;
        if (res < 0) {
            res += MAX;
        }
        std::cout << res  << std::endl;
    }
}
