#include <bits/stdc++.h>


template <class T>
std::vector<T> extendedGCD(const T& a, const T& b) {
    T q = a / b;
    T r = a % b;
    if (r == 0) {
        return {0, 1};
    }
    auto res = extendedGCD(b, r);
    return {res[1], res[0] - q * res[1]};
}


int main() {
    int a, b;
    std::cin >> a >> b;

    std::vector<int> res = extendedGCD(a, b);

    std::cout << res[0] << " " << res[1] << std::endl;
}
