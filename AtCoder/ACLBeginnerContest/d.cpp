#include <bits/stdc++.h>


int main() {
    long long int N, K;
    std::cin >> N >> K;

    std::vector<long long int> A_max(N), A_min(N);
    long long int val, max_val, min_val;
    int length = 1;
    std::cin >> val;
    A_max[0] = val;
    A_min[0] = val;
    for (long long int i = 1; i < N; i++) {
        std::cin >> val;
        max_val = val + length * K;
        min_val = val - length * K;
        if (A_max[length - 1] < max_val && A_min[length - 1] > min_val) {
            A_max[length] = max_val;
            A_min[length] = min_val;
            length++;
        } else {
            *lower_bound(A_max.begin(), A_max.begin() + length, val) = max_val;
            *lower_bound(A_min.begin(), A_min.begin() + length, val) = min_val;
        }
    }
    std::cout << length << std::endl;
}
