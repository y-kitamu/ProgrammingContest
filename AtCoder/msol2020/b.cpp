#include <bits/stdc++.h>


int main() {
    int A, B, C, K;
    std::cin >> A >> B >> C;
    std::cin >> K;

    int cnt = 0;
    while (B <= A) {
        B *= 2;
        cnt++;
    }
    while (C <= B) {
        C *= 2;
        cnt++;
    }
    if (cnt <= K) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }
}
