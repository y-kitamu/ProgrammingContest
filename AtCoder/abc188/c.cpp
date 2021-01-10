#include <bits/stdc++.h>


int main() {
    int N;
    std::cin >> N;

    int num = pow(2, N);
    std::vector<int> lhs(num / 2), rhs(num / 2);
    for (int i = 0; i < num / 2; i++) {
        std::cin >> lhs[i];
    }
    for (int i = 0; i < num / 2; i++) {
        std::cin >> rhs[i];
    }
    std::vector<int> ltmp = lhs;
    std::vector<int> rtmp = rhs;
    std::sort(ltmp.begin(), ltmp.end(), [](auto l, auto r) { return l > r; });
    std::sort(rtmp.begin(), rtmp.end(), [](auto l, auto r) { return l > r; });

    if (ltmp[0] < rtmp[0]) {
        int idx = 0;
        for (; idx < num / 2; idx++) {
            if (lhs[idx] == ltmp[0]) {
                break;
            }
        }
        std::cout << idx + 1 << std::endl;
    } else {
        int idx = 0;
        for (; idx < num / 2; idx++) {
            if (rhs[idx] == rtmp[0]) {
                break;
            }
        }
        std::cout << idx + 1 + num / 2 << std::endl;
    }
}
