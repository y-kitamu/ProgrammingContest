#include <bits/stdc++.h>


int main() {
    int A, B, C;
    std::cin >> A >> B >> C;
    if (A == B && B == C) {
        std::cout << "No" << std::endl;
    } else if (A == B || B == C || A == C) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }
}
