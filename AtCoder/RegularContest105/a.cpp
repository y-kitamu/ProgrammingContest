#include <bits/stdc++.h>


int main() {
    int A, B, C, D;
    std::cin >> A >> B >> C >> D;

    for (int i = 0; i < (1<<4); i++) {
        int sum0 = 0, sum1 = 0;
        if (i & (1<<3)) {
            sum0 += A;
        } else {
            sum1 += A;
        }
        if (i & (1<<2)) {
            sum0 += B;
        } else {
            sum1 += B;
        }
        if (i & (1<<1)) {
            sum0 += C;
        } else {
            sum1 += C;
        }
        if (i & 1) {
            sum0 += D;
        } else {
            sum1 += C;
        }
        if (sum0 == sum1) {
            std::cout << "Yes" << std::endl;
            return 0;
        }
    }
    std::cout << "No" << std::endl;
}
