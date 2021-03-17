#include <bits/stdc++.h>


int count_vec(int N, std::vector<int>& vec) {
    std::vector<int> pows(N + 1, 1);
    for (int i = 1; i <= N; i++) {
        pows[i] = pows[i - 1] * i;
    }

    int sum = 0;
    std::vector<int> flag(N, 1);
    for (int i = 0; i < N; i++) {
        int cnt = 0;
        for (int j = 0; j < vec[i] - 1; j++) {
            cnt += flag[j];
        }
        sum += cnt * pows[N - 1 - i];
        flag[vec[i] - 1] = 0;
    }
    return sum;
}


int main() {
    int N;
    std::cin >> N;
    std::vector<int> P(N), Q(N);
    for (int i = 0; i < N; i++) {
        std::cin >> P[i];
    }
    for (int i = 0; i < N; i++) {
        std::cin >> Q[i];
    }

    // std::cout << count_vec(N, P) << " " << count_vec(N, Q) << std::endl;
    std::cout << std::abs(count_vec(N, P) - count_vec(N, Q)) << std::endl;
}
