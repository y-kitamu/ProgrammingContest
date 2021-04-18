#include <bits/stdc++.h>


int main() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }
    std::sort(A.begin(), A.end());

    long long int ans = A[0] + 1;
    long long int mod = 1e9 + 7;
    for (int i = 0; i < N - 1; i++) {
        long long int diff = A[i + 1] - A[i] + 1;
        ans = (ans * diff) % mod;
    }

    std::cout << ans << std::endl;
}
