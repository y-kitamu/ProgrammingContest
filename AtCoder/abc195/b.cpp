#include <bits/stdc++.h>


int main() {
    int A, B, W;
    std::cin >> A >> B >> W;

    int min = 1e9;
    int max = -1;
    for (int i = 1; i <= W * 1000; i++) {
        double mean = 1.0 * W * 1000 / i;
        if (A <= mean && mean <= B) {
            min = std::min(min, i);
            max = std::max(max, i);
        }
    }
    if (min > max) {
        std::cout << "UNSATISFIABLE" << std::endl;
    } else {
        std::cout << min << " " << max << std::endl;
    }
}
