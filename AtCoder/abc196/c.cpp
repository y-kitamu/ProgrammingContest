#include <bits/stdc++.h>


int main() {
    long long int N;
    std::cin >> N;

    auto str = std::to_string(N);
    int max = std::pow(10, str.length() / 2 + 1);
    int cnt = 0;
    for (int i = 1; i < max; i++) {
        auto s = std::to_string(i);
        s += s;
        if (std::stoll(s) <= N) {
            cnt++;
        }
    }
    std::cout << cnt << std::endl;
}
