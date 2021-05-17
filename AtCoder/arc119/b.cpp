#include <bits/stdc++.h>


int main() {
    int N;
    std::string S, T;
    std::cin >> N >> S >> T;

    int cnt = 0;
    for (int i = 0; i < N; i++) {
        cnt += (int)(S[i] == '0') - (int)(T[i] == '0');
    }
    if (cnt != 0) {
        std::cout << -1 << std::endl;
        return 0;
    }

    auto calc = [&S, &T](auto start, auto end) {
        if (start + 1 == end) {
            return 0;
        }
        int cnt = 0;
        if (S[start] == '0') {
            std::reverse(S.begin() + start, S.begin() + end);
            std::reverse(T.begin() + start, T.begin() + end);
        }
        int lhs = start, rhs = start + 1;
        for (int i = start; i <= end; i++) {
            while (lhs < end && S[lhs] == T[lhs]) {
                lhs++;
            }
            if (lhs >= end) {
                break;
            }
            rhs = std::max(lhs + 1, rhs);

            while (rhs < end && S[rhs] == '1') {
                rhs++;
            }
            std::swap(S[lhs], S[rhs]);
            cnt++;
        }

        return cnt;
    };

    int sum = 0;
    int start = 0;
    int cnts = 0, cntt = 0;
    for (int i = 0; i < N; i++) {
        // std::cout << i << std::endl;
        cnts += (S[i] == '0');
        cntt += (T[i] == '0');

        if (cnts == cntt) {
            sum += calc(start, i + 1);
            start = i + 1;
        }
    }

    std::cout << sum << std::endl;
}
