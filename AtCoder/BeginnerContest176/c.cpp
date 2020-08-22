#include <bits/stdc++.h>


int main() {
    int N;
    std::cin >> N;
    long long int max, box = 0;
    std::cin >> max;
    for (int i = 1; i < N; i++) {
        long long int a;
        std::cin >> a;
        if (a < max) {
            box += max - a;
        } else {
            max = a;
        }
    }
    std::cout << box << std::endl;
}
