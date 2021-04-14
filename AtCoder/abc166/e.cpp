#include <bits/stdc++.h>


using ll = long long int;

int main() {
    int N;
    std::cin >> N;
    std::vector<int> A(N), diff(N);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
        diff[i] = i - A[i];
    }
    std::sort(diff.begin(), diff.end());


    ll sum = 0;
    for (int i = 0; i < N; i++) {
        auto begin = std::upper_bound(diff.begin(), diff.end(), A[i] + i - 1);
        auto end = std::upper_bound(diff.begin(), diff.end(), A[i] + i);
        ll dist = std::distance(begin, end);
        sum += dist;
    }

    std::cout << sum << std::endl;
}
