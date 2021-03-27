#include <bits/stdc++.h>


int main() {
    int N, K;
    std::cin >> N >> K;

    long long int num = K;
    long long int cnt = 1;
    while (num <= N) {
        num *= K;
        cnt++;
    }
    std::cout << cnt << std::endl;
}
