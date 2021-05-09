#include <bits/stdc++.h>


long long int sum_arr(long long int start, long long int end) {
    if (start < 0 || end < 0) {
        return 0;
    }
    return (start + end) * (start - end + 1) / 2;
}


int main() {
    long long int N, K;
    std::cin >> N >> K;

    long long int res = K;
    for (long long int l = 3; l <= 3 * N; l++) {
        long long int c0 = (l - 1) * (l - 2) / 2;
        long long int c1 = sum_arr(l - 1 - (N + 1), 0) * 3;
        long long int c2 = sum_arr(l - 1 - N - (N + 1), 0) * 3;
        long long int c = c0 - c1 + c2;
        if (res - c <= 0) {
            // i + j + k == l
            // std::cout << l << " , " << res << std::endl;
            // std::cout << "l = " << l << std::endl;
            for (long long int i = std::max(1ll, l - 2 * N); i <= N; i++) {
                long long int jk = l - i;  // sum of j and k
                long long int cnt = std::min(N, jk - 1) - std::max(1ll, jk - N) + 1;
                // std::cout << i << " " << jk << " " << cnt << std::endl;
                // std::cout << i << " " << jk << " " << cnt << std::endl;
                if (res - cnt <= 0) {
                    long long int j = std::max(1ll, jk - N) + res - 1;
                    std::cout << i << " " << j << " " << l - i - j << std::endl;
                    return 0;
                }
                res -= cnt;
            }
            // std::cout << res << std::endl;
            // break;
        }
        res -= c;
    }
}
