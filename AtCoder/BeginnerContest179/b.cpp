#include <bits/stdc++.h>


int main() {
    int N;
    std::cin >> N;
    int count = 0;
    bool flag = false;
    for (int i = 0; i < N; i++) {
        int d1, d2;
        std::cin >> d1 >> d2;
        if (d1 == d2) {
            count++;
        } else {
            count = 0;
        }
        if (count >= 3) {
            flag = true;
        }
    }
    if (flag) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }
}
