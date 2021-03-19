#include <bits/stdc++.h>


int main() {
    int a, b;
    std::cin >> a >> b;

    if (b < a) {
        std::swap(a, b);
    }
    for (int i = 0; i < b; i++) {
        std::cout << a;
    }
    std::cout << std::endl;
}
