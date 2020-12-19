#include <bits/stdc++.h>


int main() {
    int N;
    std::cin >> N;

    auto judge = [] (int val, int factor) {
        while (val > 0) {
            int res = val % factor;
            if (res == 7) {
                return false;
            }
            val /= factor;
        }
        return true;
    };

    int cnt = 0;
    for (int i = 1; i <= N; i++) {
        if (judge(i, 10) && judge(i, 8)) {
            /* std::cout << i << std::endl; */
            cnt++;
        }
    }

    std::cout << cnt << std::endl;
}
