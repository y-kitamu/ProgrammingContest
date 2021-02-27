#include <bits/stdc++.h>


int main() {
    long long int N;
    std::cin >> N;

    long long int sq = std::sqrt(N);

    long long int cnt = 0;
    std::vector<bool> flag(sq - 1, false);
    for (long long int i = 2; i <= sq; i++) {
        if (flag[i - 2]) {
            continue;
        }
        long long int val = i * i;
        while (val <= N) {
            cnt++;
            if (val - 2 <= sq) {
                flag[val - 2] = true;
            }
            val *= i;
        }
    }

    std::cout << N - cnt << std::endl;
}
