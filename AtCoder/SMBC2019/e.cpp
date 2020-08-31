#include <bits/stdc++.h>


int main() {
    long long int MOD = 1e9 + 7;
    int N;
    std::cin >> N;
    std::vector<long long int> count(3, 0);
    long long int factor = 1;
    for (int i = 0; i < N; i++) {
        long long int val;
        std::cin >> val;

        long long int fct = 0;
        bool is_updated = false;
        for (int i = 0; i < 3; i++) {
            if (count[i] == val) {
                fct++;
                if (!is_updated) {
                    count[i]++;
                    is_updated = true;
                }
            }
        }
        factor = (factor * fct) % MOD;
    }
    std::cout << factor << std::endl;
}
