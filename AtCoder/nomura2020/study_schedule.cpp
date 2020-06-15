#include <bits/stdc++.h>

int main () {
    int H1, M1, H2, M2, K;
    std::cin >> H1 >> M1 >> H2 >> M2 >> K;

    int H0 = H1 + K / 60;
    int M0 = M1 + K % 60;
    H0 += M0 / 60;
    M0 = M0 % 60;

    int hour = H2 - H0;
    int min;
    if (M0 <= M2) {
        min = M2 - M0;
    } else {
        min = M2 + 60 - M0;
        hour--;
    }
    std::cout << hour * 60 + min << std::endl;
}
