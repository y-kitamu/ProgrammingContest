#include <bits/stdc++.h>

int D;

int calc_score(const std::vector<int> &t, const std::vector<int> &c, const std::vector<std::vector<int>> &s) {
    std::vector<int> last(26, 0);
    int score = 0;
    for (int i = 0; i < D; i++) {
        score += s[i][t[i] - 1];
        last[t[i] - 1] = i + 1;
        for (int j = 0; j < 26; j++) {
            score -= c[j] * (i + 1 - last[j]);
        }
        std::cout << score << std::endl;
    }
    return score;
}


int main() {
    std::cin >> D;

    std::vector<int> c(26);
    for (int i = 0; i < 26; i++) {
        std::cin >> c[i];
    }

    std::vector<std::vector<int>> s(D, std::vector<int>(26));
    for (int i = 0; i < D; i++) {
        for (int j = 0; j < 26; j++) {
            std::cin >> s[i][j];
        }
    }

    std::vector<int> t(D);
    for (int i = 0; i < D; i++) {
        std::cin >> t[i];
    }

    calc_score(t, c, s);
}
