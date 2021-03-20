#include <bits/stdc++.h>


int main() {
    long long int N, K;
    std::cin >> N >> K;

    std::vector<long long int> vec(N);
    for (int i = 0; i < N; i++) {
        std::cin >> vec[i];
    }

    long long int cnt = 0;
    std::sort(vec.begin(), vec.end());
    for (int i = 0; i < N - K; i++) {
        cnt += vec[i];
    }

    std::cout << cnt << std::endl;
}
