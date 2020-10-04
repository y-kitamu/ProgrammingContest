#include <bits/stdc++.h>


int main() {
    int N;
    std::string S;
    std::cin >> N >> S;

    std::vector<std::vector<int>> counts(N + 1, std::vector<int>(4, 0));
    for (int i = 1; i <= N; i++) {
        int idx;
        if (S[i - 1] == 'A') {
            idx = 0;
        } else if (S[i - 1] == 'T') {
            idx = 1;
        } else if (S[i - 1] == 'G') {
            idx = 2;
        } else if (S[i - 1] == 'C') {
            idx = 3;
        }
        for (int j = 0; j < 4; j++) {
            if (j == idx) {
                counts[i][j] = counts[i - 1][j] + 1;
            } else {
                counts[i][j] = counts[i - 1][j];
            }
        }
    }

    int count = 0;
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 2; j <= N; j++) {
            int num_a = counts[j][0] - counts[i][0];
            int num_t = counts[j][1] - counts[i][1];
            int num_g = counts[j][2] - counts[i][2];
            int num_c = counts[j][3] - counts[i][3];
            if (num_a == num_t && num_g == num_c) {
                count++;
            }
        }
    }
    std::cout << count << std::endl;
}
