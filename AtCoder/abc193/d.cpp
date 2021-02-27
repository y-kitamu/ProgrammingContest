#include <bits/stdc++.h>


int main() {
    long long int K;
    std::cin >> K;
    std::string S, T;
    std::cin >> S >> T;

    std::vector<int> cnt0(9, 0), cnt1(9, 0);
    for (int i = 0; i < 4; i++) {
        cnt0[S[i] - '1']++;
        cnt1[T[i] - '1']++;
    }

    std::vector<int> score0(9, 0), score1(9, 0);

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (i == j) {
                score0[i] += (j + 1) * std::pow(10, cnt0[j] + 1);
                score1[i] += (j + 1) * std::pow(10, cnt1[j] + 1);
            } else {
                score0[i] += (j + 1) * std::pow(10, cnt0[j]);
                score1[i] += (j + 1) * std::pow(10, cnt1[j]);
            }
        }
    }

    std::vector<int> res(9, K);
    for (int i = 0; i < 9; i++) {
        res[i] -= (cnt0[i] + cnt1[i]);
    }

    long long int cnt = 0;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            long long int factor = res[i];
            long long int f2 = res[j];
            if (i == j) {
                f2--;
            }
            factor *= f2;
            if (score0[i] > score1[j]) {
                cnt += factor;
            }
        }
    }

    long long int val = (9 * K - 8) * (9 * K - 9);
    std::cout << std::fixed << std::setprecision(10) << (double)cnt / val << std::endl;
}
