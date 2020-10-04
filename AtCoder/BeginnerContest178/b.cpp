#include <bits/stdc++.h>


int main() {
    long long int a, b, c, d;
    std::cin >> a >> b >> c >> d;
    long long int max = std::max(a * c, a * d);
    max = std::max(b * c, max);
    max = std::max(b * d, max);
    std::cout << max << std::endl;
}
