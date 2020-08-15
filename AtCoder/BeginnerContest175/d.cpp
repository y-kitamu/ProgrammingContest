#include <bits/stdc++.h>


long long int N, K;
std::vector<long long int> C, P;

long long int calc_max(std::vector<long long int> loop_vec) {
    long long int sum = 0;
    for (int j = 0; j < loop_vec.size(); j++) {
        sum += loop_vec[j];
    }
    long long int n_loop = loop_vec.size();
    long long int loop = std::max(0ll, (K - n_loop) / n_loop);
    int count = K - loop * n_loop;
    long long int max = loop_vec[0];
    int n_max = 1;
    for (int i = 0; i < n_loop; i++) {
        long long int s = 0;
        for (int j = 0; j < count; j++) {
            s += loop_vec[(i + j) % n_loop];
            if (s > max) {
                max = s;
                n_max = j + 1;
            }
        }
    }
    if (sum > 0) {
        max += sum * loop;
    }
    return max;
}


int main() {
    std::cin >> N >> K;

    C = std::vector<long long int>(N);
    P = std::vector<long long int>(N);
    for (int i = 0; i < N; i++) {
        std::cin >> C[i];
        C[i]--;
    }

    for (int i = 0; i < N; i++) {
        std::cin >> P[i];
    }

    long long int max = -200000000000;
    std::vector<int> flag(N, -1);
    for (int i = 0; i < N; i++) {
        if (flag[i] != -1) {
            continue;
        }
        std::vector<long long int> loop {P[i]};
        flag[i] = 1;
        int next = i;
        while (C[next] != i) {
            next = C[next];
            loop.emplace_back(P[next]);
            flag[next] = 1;
        }
        max = std::max(max, calc_max(loop));
    }
    std::cout << max << std::endl;
}
