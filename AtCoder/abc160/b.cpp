#include <bits/stdc++.h>


int main() {
    long long int X;
    std::cin >> X;
    long long int ans = X / 500 * 1000;
    ans += (X % 500) / 5 * 5;
    std::cout << ans << std::endl;
}
