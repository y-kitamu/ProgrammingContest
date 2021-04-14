#include <bits/stdc++.h>


int main() {
    int N, A, B, C;
    std::cin >> N >> A >> B >> C;

    std::vector<std::string> a(N);
    for (int i = 0; i < N; i++) {
        std::cin >> a[i];
    }

    auto update = [&a, &N](int idx, auto& lhs, auto& rhs) {
        bool is_left = true;
        if (idx < N - 1 && lhs == 1 && rhs == 1) {
            auto s0 = a[idx], s1 = a[idx + 1];
            if (s0 == s1) {
                lhs++;
                rhs--;
            } else {
                if (s0[0] == s1[0]) {
                    lhs++;
                    rhs--;
                } else if (s0[1] == s1[1]) {
                    is_left = false;
                    lhs--;
                    rhs++;
                } else {
                    if (s0[0] == 'B') {
                        lhs++;
                        rhs--;
                    } else {
                        is_left = false;
                        lhs--;
                        rhs++;
                    }
                }
            }
        } else {
            if (lhs > rhs) {
                is_left = false;
                lhs--;
                rhs++;
            } else {
                lhs++;
                rhs--;
            }
        }
        return is_left ? a[idx][0] : a[idx][1];
    };

    std::vector<char> ans(N);
    bool success = true;
    for (int i = 0; i < N; i++) {
        if (a[i] == "AB") {
            ans[i] = update(i, A, B);
        } else if (a[i] == "AC") {
            ans[i] = update(i, A, C);
        } else {
            ans[i] = update(i, B, C);
        }
        if (A < 0 || B < 0 || C < 0) {
            success = false;
            break;
        }
    }

    if (success) {
        std::cout << "Yes" << std::endl;
        for (auto& c : ans) {
            std::cout << c << std::endl;
        }
    } else {
        std::cout << "No" << std::endl;
    }
}
