#include <bits/stdc++.h>


int main() {
    int t;
    std::cin >> t;

    for (int k = 0; k < t; k++) {
        int n, x;
        std::cin >> n >> x;
        std::vector<int> ratings(n);
        int diff = 0;
        int flag = true;

        int sum = 0;
        int count = 0;
        for (int i = 0; i < n; i++) {
            std::cin >> ratings[i];
            if (ratings[i] == x) {
                count++;
            } else {
                sum += ratings[i];
                flag = false;
            }
        }
        if (flag) {
            std::cout << 0 << std::endl;
            continue;
        }

        flag = false;
        for (int i = 1; i <= count; i++) {
            if ((sum + i * x) % (n - count + i) == 0) {
                flag = true;
                break;
            }
        }

        if (flag) {
            std::cout << 1 << std::endl;
            continue;
        }

        for (int i = 0; i < n; i++) {
            diff += ratings[i] - x;
        }

        if (diff == 0) {
            std::cout << 1 << std::endl;
        } else {
            std::cout << 2 << std::endl;
        }
    }
}
