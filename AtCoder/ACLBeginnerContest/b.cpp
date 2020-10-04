#include <bits/stdc++.h>


int main() {
    long long int a, b, c, d;
    std::cin >> a >> b >> c >> d;

    if ((a - d > 0) == (c - b > 0)) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }
}
