#include <bits/stdc++.h>


int main() {
    int N;
    std::cin >> N;

    std::vector<int> a(N);
    int sum = 0;
    for (int i = 0; i < N; i++) {
        std::cin >> a[i];
        sum = sum ^ a[i];
    }
    for (int i = 0; i < N - 1; i++) {
        std::cout << (sum ^ a[i]) << " ";
    }
    std::cout << (sum ^ a[N - 1]) << std::endl;
}
