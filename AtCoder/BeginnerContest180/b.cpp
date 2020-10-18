#include <bits/stdc++.h>


int main() {
    int N;
    std::cin >> N;
    long long int m = 0, u = 0, c = 0;
    for (int i = 0; i < N; i++) {
        long long int x;
        std::cin >> x;
        m += std::abs(x);
        u += x * x;
        c = std::max(std::abs(x), c);
    }
    double ud = std::sqrt(u);
    std::cout << m << std::endl;
    std::cout << std::fixed << std::setprecision(15) << ud << std::endl;
    std::cout << c << std::endl;

}
