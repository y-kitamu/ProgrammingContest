#include <bits/stdc++.h>


int main() {
    int A, B;
    std::cin >> A >> B;
    auto func = [] (int val) {
        return val / 100 + (val % 100) / 10 + (val % 10);
    };
    std::cout << std::max(func(A), func(B)) << std::endl;
}
