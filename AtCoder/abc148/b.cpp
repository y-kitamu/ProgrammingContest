#include <bits/stdc++.h>


int main() {
    int N;
    std::cin >> N;
    std::string S, T;
    std::cin >> S >> T;
    std::string res = "";
    for (int i = 0; i < N; i++) {
        res += S[i];
        res += T[i];
    }
    std::cout << res << std::endl;
}
