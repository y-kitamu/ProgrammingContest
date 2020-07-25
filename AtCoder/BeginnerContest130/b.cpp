#include <bits/stdc++.h>


int main() {
    int N, X;
    std::cin >> N >> X;

    std::vector<int> L(N);
    for (int i = 0; i < N; i++) {
        std::cin >> L[i];
    }

    int count = 0;
    int pos = 0;
    while (count < N + 1 && pos <= X) {
        count++;
        pos = pos + L[count - 1];
    }
    std::cout << count << std::endl;
}
