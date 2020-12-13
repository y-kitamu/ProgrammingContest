#include <bits/stdc++.h>


int main() {
    long long int N, M, T;
    std::cin >> N >> M >> T;

    long long int res = N;
    int last = 0;
    int a, b;
    bool flag = true;
    for (int i = 0; i < M; i++) {
        std::cin >> a >> b;
        res -= (a - last);
        if (res <= 0) {
            flag = false;
        }
        res += (b - a);
        res = std::min(res, N);
        last = b;
    }
    res -= (T - last);
    if (res <= 0) {
        flag = false;
    }

    if (flag) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" <<std::endl;
    }
}
