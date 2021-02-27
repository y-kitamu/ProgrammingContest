#include <bits/stdc++.h>


int main() {
    int N;
    std::cin >> N;

    long long int a, p, x;
    long long int min = -1;
    for (int i = 0; i < N; i++) {
        std::cin >> a >> p >> x;
        if (a < x) {
            if (min != -1) {
                min = std::min(p, min);
            } else {
                min = p;
            }
        }
    }
    std::cout << min << std::endl;
}
