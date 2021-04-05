#include <bits/stdc++.h>


int main() {
    int N, K, C;
    std::string S;
    std::cin >> N >> K >> C >> S;

    std::vector<int> left(N), right(N);
    left[0] = 1;
    for (int i = 1; i < N; i++) {
        if (i > C && S[i] == 'o') {
            left[i] = left[i - C - 1] + 1;
        } else {
            left[i] = left[i - 1];
        }
    }

    right[N - 1] = K;
    for (int i = N - 2; i >= 0; i--) {
        if (i + C + 1 < N && S[i] == 'o') {
            right[i] = right[i + C + 1] - 1;
        } else {
            right[i] = right[i + 1];
        }
    }

    // auto print_vec = [](std::vector<int>& vec) {
    //     for (auto& val : vec) {
    //         std::cout << val << " ";
    //     }
    //     std::cout << std::endl;
    // };
    // print_vec(left);
    // print_vec(right);

    std::vector<std::vector<int>> days(K);
    for (int i = 0; i < N; i++) {
        if (S[i] == 'o' && left[i] == right[i]) {
            days[left[i] - 1].emplace_back(i + 1);
        }
    }

    for (int i = 0; i < days.size(); i++) {
        if (days[i].size() == 1) {
            std::cout << days[i][0] << std::endl;
        }
    }
}
