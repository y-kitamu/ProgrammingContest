#include <bits/stdc++.h>


using ll = long long int;


bool judge(ll val, ll K, std::vector<ll>& A, std::vector<ll>& F) {
    ll costs = 0;
    for (int i = 0; i < A.size(); i++) {
        ll cost = val / F[i];
        costs += std::max(A[i] - cost, 0ll);
    }
    return costs <= K;
}


long long int binarySearch(ll min, ll max, ll K, std::vector<ll>& A, std::vector<ll>& F) {
    if (min == max) {
        return min;
    }
    ll center = (min + max) / 2;
    if (judge(center, K, A, F)) {
        return binarySearch(min, center, K, A, F);
    }
    return binarySearch(center + 1, max, K, A, F);
}


int main() {
    long long int N, K;
    std::cin >> N >> K;

    std::vector<ll> A(N), F(N);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }
    std::sort(A.begin(), A.end());
    for (int i = 0; i < N; i++) {
        std::cin >> F[i];
    }
    std::sort(F.begin(), F.end(), std::greater<ll>());

    long long int MAX = 1e12;
    std::cout << binarySearch(0, MAX, K, A, F) << std::endl;
}
