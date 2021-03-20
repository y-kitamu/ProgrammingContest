#include <bits/stdc++.h>


int main() {
    long long int H;
    std::cin >> H;

    long long int val = 1;
    while (val <= H) {
        val *= 2;
    }
    std::cout << val - 1 << std::endl;
}
