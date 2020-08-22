#include <bits/stdc++.h>


int main() {
    int N, D;
    std::cin >> N >> D;
    int cover = D * 2 + 1;
    int n = (N + cover - 1) / cover;
    std::cout << n << std::endl;
}
