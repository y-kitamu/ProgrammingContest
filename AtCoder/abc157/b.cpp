#include <bits/stdc++.h>


int main() {
    std::vector<int> bingo(9);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cin >> bingo[i * 3 + j];
        }
    }

    int N;
    std::cin >> N;
    std::vector<int> flag(9, false);
    for (int i = 0; i < N; i++) {
        int val;
        std::cin >> val;
        for (int i = 0; i < 9; i++) {
            if (bingo[i] == val) {
                flag[i] = true;
                break;
            }
        }
    }

    bool is_bingo = false;
    for (int i = 0; i < 3; i++) {
        is_bingo |= (flag[i * 3] && flag[i * 3 + 1] && flag[i * 3 + 2]);
        is_bingo |= (flag[i] && flag[i + 3] && flag[i + 6]);
    }
    is_bingo |= (flag[0] && flag[4] && flag[8]);
    is_bingo |= (flag[2] && flag[4] && flag[6]);
    if (is_bingo) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }
}
