#include <bits/stdc++.h>


int main() {
    long long int N, K;
    std::cin >> N >> K;
    std::string S;
    std::cin >> S;

    int idx = 1;
    int cnt = 0;
    while (cnt < K) {
        for (; idx < S.length(); idx++) {
            if (S[idx - 1] != S[idx]) {
                break;
            }
        }
        if (idx == S.length()) {
            break;
        }
        idx++;

        for (; idx < S.length(); idx++) {
            if (S[idx - 1] != S[idx]) {
                break;
            }
        }
        if (idx == S.length()) {
            break;
        }
        idx++;
        cnt++;
    }

    int num = idx - 1;
    for (;idx < S.length(); idx++) {
        if (S[idx - 1] == S[idx]) {
            num++;
        }
    }
    std::cout << num << std::endl;
}
