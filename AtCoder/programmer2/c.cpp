#include <bits/stdc++.h>


int main() {
    int A, B;
    std::cin >> A >> B;

    int diff = B - A;
    for (int i = diff; i >= 1; i--) {
        if ((A + i - 1) / i != B / i) {
            std::cout << i << std::endl;
            return 0;
        }
    }
}
