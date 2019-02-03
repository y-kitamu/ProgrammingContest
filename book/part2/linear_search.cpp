#include <iostream>


int main() {
    int N, Q;
    std::cin >> N;

    int S[N + 1];
    for (int i = 0; i < N; i++) {
        std::cin >> S[i];
    }

    std::cin >> Q;
    int cnt = 0;
    for (int i = 0; i < Q; i++) {
        int val;
        std::cin >> val;
        S[N] = val;
        int idx = 0;
        while (S[idx] !=  val) {
            idx++;
        }
        if (idx != N) {
            cnt++;
        }
    }

    std::cout << cnt << std::endl;
}
