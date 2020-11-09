#include <bits/stdc++.h>


int main() {
    int N;
    std::cin >> N;
    std::vector<int> as(N);
    for (int i = 0; i < N; i++) {
        std::cin >> as[i];
    }

    int max = 2, max_num = 0;
    for (int k = 2; k < 1000; k++) {
        int cnt = 0;
        for (int i = 0; i < N; i++) {
            if (as[i] % k == 0) {
                cnt++;
            }
        }
        if (cnt > max_num) {
            max_num = cnt;
            max = k;
        }
    }
    std::cout << max << std::endl;
}
