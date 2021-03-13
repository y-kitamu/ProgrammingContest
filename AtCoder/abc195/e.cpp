#include <bits/stdc++.h>


int main() {
    int N;
    std::string S, X;
    std::cin >> N >> S >> X;

    int last = N;
    while (X[last - 1] == 'T') {
        last--;
    }

    std::vector<int> mods(7, 0);
    for (int i = 0; i < last; i++) {
        std::vector<int> new_mods(7, 0);
        new_mods[S[i] - '0'] = 1;
        for (int j = 0; j < 7; j++) {
            if (mods[j] > 0) {
                int base = j * 10 % 7;
                new_mods[base] = 1;
                new_mods[(base + S[i] - '0') % 7] = 1;
            }
        }
        mods = new_mods;
    }

    bool win_t = true;

    if (X[N - 1] == 'A') {
        last = N;
        bool all_zero = true;
        while (last > 0 && X[last - 1] == 'A') {
            last--;
            all_zero &= (S[last] == '0' || S[last] == '7');
        }
        if (all_zero) {
            win_t = (mods[0] > 0 || last == 0);
        } else {
            win_t = false;
        }
    } else {
        for (int k = 0; k < 7; k++) {
            if (mods[k] > 0) {
                std::vector<int> ans(7, 0);
                ans[k] = 1;
                for (int i = last; i < N; i++) {
                    std::vector<int> new_mods(7, 0);
                    for (int j = 0; j < 7; j++) {
                        if (ans[j] > 0) {
                            int base = j * 10 % 7;
                            new_mods[base] = 1;
                            new_mods[(base + S[i] - '0') % 7] = 1;
                        }
                    }
                    ans = new_mods;
                }
                win_t &= ans[0] > 0;
            }
        }
    }


    if (win_t) {
        std::cout << "Takahashi" << std::endl;
    } else {
        std::cout << "Aoki" << std::endl;
    }
}
