#include <bits/stdc++.h>


int main() {
    int N;
    std::string S;
    std::cin >> N >> S;

    char cur = S[0];
    int cnt = 1;
    for (int i = 1; i < N; i++) {
        if (cur == S[i]) {
            continue;
        }
        cur = S[i];
        cnt++;
    }

    std::cout << cnt << std::endl;
}
