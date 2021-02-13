#include <bits/stdc++.h>


int main() {
    long long int B, C;
    std::cin >> B >> C;

    long long int cnt = 0;
    long long int b0 = B - C / 2;
    long long int b1 = -B - (C - 1) / 2;
    if (B == 0) {
        cnt = C;
    } else if (C == 1) {
        cnt = 2;
    } else {
        if (C % 2 == 0) {
            if (B > 0) {
                if (b0 <= 0) {
                    cnt = std::abs(b1) * 2 + 1;
                } else {
                    cnt = (-B - b1) * 2 + (B - b0) * 2 + 1;
                }
            } else {
                if (b1 <= 0) {
                    cnt = std::abs(b0) * 2;
                } else {
                    cnt = (B - b0) * 2 + 1 + (-B - b1) * 2;
                }
            }
        } else {
            if (B > 0) {
                if (b0 <= 0) {
                    cnt = std::abs(b1) * 2;
                } else {
                    cnt = (B - b0) * 2 + (-B - b1) * 2 + 1;
                }
            } else {
                if (b1 <= 0) {
                    cnt = std::abs(b0) * 2;
                } else {
                    cnt = (-B - b1) * 2 + 1 + (B - b0) * 2;
                }
            }
        }
    }
    std::cout << cnt << std::endl;
}
