#include <bits/stdc++.h>


int main() {
    int n;
    std::cin >> n;

    int p0, p1, p2;
    int count = 0;
    std::cin >> p0 >> p1;
    for (int i = 2; i < n; i++) {
        std::cin >> p2;
        if (p0 <= p1 && p1 < p2) {
            count++;
        } else if (p2 <= p1 && p1 < p0) {
            count++;
        }
        p0 = p1;
        p1 = p2;
    }
    std::cout << count << std::endl;
}
