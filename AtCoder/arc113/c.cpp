#include <bits/stdc++.h>


int main() {
    std::string S;
    std::cin >> S;

    std::vector<int> cnts(26, 0);
    std::reverse(S.begin(), S.end());

    long long int rev = 0;
    cnts[S[0] - 'a']++;
    for (int i = 1; i < S.length() - 1; i++) {
        if (S[i] == S[i + 1]) {
            rev += i - cnts[S[i] - 'a'];
            cnts = std::vector<int>(26, 0);
            cnts[S[i] - 'a'] = i + 1;
        } else {
            cnts[S[i] - 'a']++;
        }
    }
    std::cout << rev << std::endl;
}
