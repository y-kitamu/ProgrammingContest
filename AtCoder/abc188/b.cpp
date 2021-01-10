#include <bits/stdc++.h>


int main() {
    int N;
    std::cin >> N;
    std::vector<long long int> a(N), b(N);
    for (int i = 0; i < N; i++) {
        std::cin >> a[i];
    }
    for (int i = 0; i < N; i++) {
        std::cin >> b[i];
    }
    long long int sum = 0;
    for (int i = 0; i < N; i++) {
        sum += a[i] * b[i];
    }
    if (sum == 0) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }
}
