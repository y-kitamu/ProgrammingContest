#include <bits/stdc++.h>


int main() {
    int a1, a2, a3, a4;
    std::cin >> a1 >> a2 >> a3 >> a4;
    int a12 = std::min(a1, a2);
    int a34 = std::min(a3, a4);
    std::cout << std::min(a12, a34) << std::endl;
}
