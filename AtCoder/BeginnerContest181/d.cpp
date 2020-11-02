#include <bits/stdc++.h>


bool check(std::vector<int> cnts, int i, int j, int k) {
    cnts[i]--;
    cnts[j]--;
    cnts[k]--;
    if (cnts[i] < 0 || cnts[j] < 0 || cnts[k] < 0)  {
        return false;
    }
    return ((i + 1) * 100 + (j + 1) * 10 + k + 1) % 8 == 0;
}


int main() {
    std::string S;
    std::cin >> S;

    std::vector<int> cnts(9, 0);
    for (auto c : S) {
        cnts[c - '1']++;
    }

    if (S.length() == 1) {
        if ((S[0] - '0') % 8 == 0) {
            std::cout << "Yes" << std::endl;
        } else {
            std::cout << "No" << std::endl;
        }
        return 0;
    } else if (S.length() == 2) {
        int a = S[0] - '0';
        int b = S[1] - '0';
        if ((a * 10 + b) % 8 == 0 || (b * 10 + a) % 8 == 0) {
            std::cout << "Yes" << std::endl;
        } else {
            std::cout << "No" << std::endl;
        }
        return 0;
    }

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            for (int k = 0; k < 9; k++) {
                if (check(cnts, i, j, k)) {
                    std::cout << "Yes" << std::endl;
                    return 0;
                }
            }
        }
    }
    std::cout << "No" << std::endl;
}
