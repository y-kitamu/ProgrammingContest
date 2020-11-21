#include <bits/stdc++.h>



int main() {
    long long int S, P;
    std::cin >> S >> P;

    long long int max = std::sqrt(P) + 1;
    bool flag = false;
    for (long long int i = 1; i < max; i ++) {
        if (P % i == 0 && (S - i) * i == P) {
            flag = true;
            break;
        }
    }
    if (flag) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }
}
