#include <bits/stdc++.h>


int main() {
    int N;
    std::cin >> N;

    std::vector<int> order(N);
    for (int i = 0; i < N; i++) {
        int a;
        std::cin >> a;
        order[--a] = i + 1;
    }

    std::cout << order[0];
    for (int i = 1; i < N; i++) {
        std::cout << " " << order[i];
    }
    std::cout << std::endl;
}
