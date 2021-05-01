#include <bits/stdc++.h>

int main() {
    std::string zone = "ZONe";
    std::string S;
    std::cin >> S;

    int cnt = 0;
    for (int i = 0; i <= S.length() - zone.length(); i++) {
        bool flag = true;
        for (int j = 0; j < zone.length(); j++) {
            flag &= zone[j] == S[i + j];
        }
        if (flag) {
            cnt++;
        }
    }
    std::cout << cnt << std::endl;
}
