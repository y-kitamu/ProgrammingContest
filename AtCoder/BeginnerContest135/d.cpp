#include <bits/stdc++.h>

struct Node {
    int min=0, max=0;
};

int main() {
    std::string S;
    std::cin >> S;

    long long int MOD = 1e9 + 7;
    int res = 0, mod_i = 1;
    int N = S.length();
    std::vector<long long int> before(13, 0);
    before[0] = 1;
    for (int i = 0; i < N; i++) {
        auto c = S[N - 1 - i];
        if (c == '?') {
            std::vector<long long int> after(13, 0);
            for (int j = 0; j <= 9; j++) {
                int diff = (mod_i * j) % 13;
                for (int k = 0; k < 13; k++) {
                    int idx = (k + diff) % 13;
                    after[idx] = (before[k] + after[idx]) % MOD;
                }
            }
            before = after;
        } else {
            int val = (int)(c - '0');
            res += mod_i * val;
        }
        mod_i = (mod_i * 10) % 13;
    }
    res %= 13;
    int idx = (5 - res + 13) % 13;
    std::cout << before[idx] << std::endl;
}
