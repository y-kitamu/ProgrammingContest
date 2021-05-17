#include <bits/stdc++.h>


int main() {
    int N;
    std::cin >> N;

    std::vector<long long int> A(N);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
        if (i % 2 == 1) {
            A[i] *= -1;
        }
    }

    std::vector<long long int> sum(N + 1, 0);
    std::map<long long int, long long int> map;
    map[0] = 1;
    for (int i = 0; i < N; i++) {
        sum[i + 1] = sum[i] + A[i];
        if (map.find(sum[i + 1]) == map.end()) {
            map[sum[i + 1]] = 0;
        }
        map[sum[i + 1]]++;
    }

    long long int res = 0;
    for (auto& pair : map) {
        if (pair.second < 2) {
            continue;
        }
        res += pair.second * (pair.second - 1) / 2;
    }
    std::cout << res << std::endl;
}
