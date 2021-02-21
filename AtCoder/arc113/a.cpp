#include <bits/stdc++.h>


int main() {
    int K;
    std::cin >> K;

    int cnt = 0;
    for (int a = 1; a <= K; a++) {
        for (int b = a; b <= K / a; b++) {
            for (int c = b; c <= K / (a * b); c++) {
                if (a == b && b == c) {
                    cnt++;
                } else if (a == b || b == c) {
                    cnt += 3;
                } else {
                    cnt += 6;
                }
            }
        }
    }
    std::cout << cnt << std::endl;
}
