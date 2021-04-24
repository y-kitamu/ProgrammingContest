#include <bits/stdc++.h>


int main() {
    int N, Q;
    std::string S;
    std::cin >> N >> S >> Q;

    bool is_flip = false;
    for (int i = 0; i < Q; i++) {
        int t, a, b;
        std::cin >> t >> a >> b;
        a--;
        b--;
        if (t == 1) {
            if (is_flip) {
                a = (a + N) % (2 * N);
                b = (b + N) % (2 * N);
            }
            std::swap(S[a], S[b]);
        } else {
            is_flip = !is_flip;
        }
    }

    if (is_flip) {
        S = S.substr(N, N) + S.substr(0, N);
    }

    std::cout << S << std::endl;
}
