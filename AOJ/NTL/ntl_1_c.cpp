#include <bits/stdc++.h>


int lcm(int a, int b) {
    int c = a * b;
    while (b > 0) {
        int tmp = b;
        b = a % b;
        a = tmp;
    }
    return c / a;
}


int main() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    int min = a[0];
    for (int i = 1; i < n; i++) {
        min = lcm(min, a[i]);
    }

    std::cout << min << std::endl;
}
