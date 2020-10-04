#include <bits/stdc++.h>


int main() {
    int S;
    std::cin >> S;

    long long int mod = 1e9 + 7;
    std::vector<long long int> sums(S);
    sums[0] = 0;
    sums[1] = 0;
    for (int i = 2; i < S; i++) {
        sums[i] = 1;
        for (int j = 0; j <= i - 3; j++) {
            sums[i] = (sums[i] + sums[j]) % mod;
        }
    }
    std::cout << sums[S - 1] << std::endl;
}
