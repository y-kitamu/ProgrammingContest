#include <bits/stdc++.h>

int gcd(int a, int b) {
    if (a < b) {
        std::swap(a, b);
    }
    while (b > 0) {
        int tmp_b = a - b * (a / b);
        a = b;
        b = tmp_b;
    }
    return a;
}


int main() {
    // ~5:06
    int N, K;
    std::cin >> N >> K;
    std::vector<int> vals(N);
    std::cin >> vals[0];
    int g = vals[0];
    int max_val = vals[0];
    for (int i = 1; i < N; i++) {
        std::cin >> vals[i];
        if (vals[i] > max_val)  {
            max_val = vals[i];
        }
        g = gcd(vals[i], g);
    }

    if (K % g == 0 && K <= max_val) {
        std::cout << "POSSIBLE" << std::endl;
    } else {
        std::cout << "IMPOSSIBLE" << std::endl;
    }
}
