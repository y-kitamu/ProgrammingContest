#include <bits/stdc++.h>


int main() {
    int N, M;
    std::cin >> N >> M;
    std::vector<std::string> S(N);
    long long int odd = 0, even = 0;
    for (int i = 0; i < N; i++) {
        std::cin >> S[i];
        int cnt0 = 0;
        for (auto& c : S[i]) {
            if (c == '0') {
                cnt0++;
            }
        }
        if (cnt0 % 2 == 0) {
            even++;
        } else {
            odd++;
        }
    }
    std::cout << even * odd << std::endl;
}
