#include <bits/stdc++.h>


int main() {
    int N;
    std::cin >> N;
    std::vector<int> ps(N);
    for (int i = 0; i < N; i++) {
        std::cin >> ps[i];
    }

    std::vector<int> cnts(200000, 0);
    int min = 0;
    for (int i = 0; i < N; i++) {
        cnts[ps[i]]++;
        while (cnts[min] > 0) {
            min++;
        }
        std::cout << min << std::endl;
    }
}
