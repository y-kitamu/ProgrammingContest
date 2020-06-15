#include <bits/stdc++.h>


int main() {
    long long int A, B, V, W, T;
    std::cin >> A >> V >> B >> W >> T;

    if (V - W <= 0) {
        std::cout << "NO" << std::endl;
        return 0;
    }


    if (std::abs(B - A) <= (V - W) * T) {
        std::cout << "YES"  << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }
}
