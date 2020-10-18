#include <bits/stdc++.h>


int gcd(int a, int b) {
    while (b > 0) {
        int tmp = b;
        b = a % b;
        a = tmp;
    }
    return a;
}


int main() {
    int N;
    std::cin >> N;

    std::vector<int> as(N);
    int max_gcd, val;
    std::cin >> max_gcd;
    for (int i = 1; i < N; i++) {
        std::cin >> val;
        max_gcd = gcd(max_gcd, val);
    }

    std::cout << max_gcd << std::endl;
}
