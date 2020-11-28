#include <bits/stdc++.h>


int main() {
    long long int n;
    std::cin >> n;
    double res = std::sqrt((double)2) * std::sqrt((double)(n + 1));
    long long int max = (long long int)res + 1;
    for (long long int i = max; i >= 1; i--) {
        if ((i + 1) * i / 2 <= n + 1) {
            std::cout << n - i + 1 << std::endl;
            break;
        }
    }
}
