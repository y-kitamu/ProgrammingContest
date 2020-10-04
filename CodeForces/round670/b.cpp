#include <bits/stdc++.h>


long long int calcMaximumValue(std::vector<long long int>& A) {
    std::sort(A.begin(), A.end(), [](auto lhs, auto rhs){ return lhs > rhs; });
    long long int maximum = A[0] * A[1] * A[2] * A[3] * A[4];
    int n = A.size();
    maximum = std::max(maximum, A[0] * A[n - 1] * A[n - 2] * A[n - 3] * A[n - 4]);
    maximum = std::max(maximum, A[0] * A[1] * A[2] * A[n - 1] * A[n - 2]);
    return maximum;
}


int main() {
    int t;
    std::cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        std::cin >> n;
        std::vector<long long int> A(n);
        for (int j = 0; j < n; j++) {
            std::cin >> A[j];
        }
        std::cout << calcMaximumValue(A) << std::endl;;
    }

}
