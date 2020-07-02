#include <bits/stdc++.h>

int D;
std::vector<int> c(26);
std::vector<std::vector<int>> s(365, std::vector<int>(26));
std::vector<int> t(365);

void calc_greedy_score() {
    std::vector<int> last(26, 0);
    for (int i = 0; i < D; i++) {
        int max_idx = 0;
        int max_score = -365 * 100 * 26;
        for (int j = 0; j < 26; j++) {
            int tmp_score = 0;
            for (int k = 0; k < 26; k++) {
                if (j != k) {
                    tmp_score -= c[k] * (i + 1 - last[k]);
                }
            }
            tmp_score += s[i][j];
            if (tmp_score > max_score) {
                max_idx = j;
                max_score = tmp_score;
            }
        }
        last[max_idx] = i + 1;
        t[i] = max_idx + 1;
    }
}


int calc_diff(int day, int cont) {
    int pre_day = day - 1;
    for (; pre_day >= 0; pre_day--) {
        if (t[pre_day] - 1 == cont) {
            break;
        }
    }
    int post_day = day + 1;
    for (; post_day < D; post_day++) {
        if (t[post_day] - 1 == cont) {
            break;
        }
    }
    return (day - pre_day) * (post_day - day) * c[cont];
}


void update_score(int day, int after_cont) {
    int before_cont = t[day] - 1;
    if (calc_diff(day, after_cont) - calc_diff(day, before_cont) + s[day][after_cont] - s[day][before_cont] > 0) {
        t[day] = after_cont + 1;
    };
}


int main() {
    std::cin >> D;

    for (int i = 0; i < 26; i++) {
        std::cin >> c[i];
    }

    for (int i = 0; i < D; i++) {
        for (int j = 0; j < 26; j++) {
            std::cin >> s[i][j];
        }
    }

    calc_greedy_score();

    std::random_device seed_gen;
    std::mt19937 engine(seed_gen());
    std::uniform_int_distribution<> dist1(0, 364);
    std::uniform_int_distribution<> dist2(0, 25);

    for (int i = 0; i < 10000000; i++) {
        update_score(dist1(engine), dist2(engine));
    }

    for (auto val : t) {
        std::cout  << val << std::endl;
    }
}
