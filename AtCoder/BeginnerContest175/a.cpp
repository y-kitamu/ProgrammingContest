#include <bits/stdc++.h>

int main() {
    std::string S;
    std::cin >> S;

    int max_count = 0;
    int count = 0;
    for (auto s : S) {
        if (s == 'R') {
            count++;
        } else {
            max_count = std::max(count, max_count);
            count = 0;
        }
    }
    max_count = std::max(count, max_count);
    std::cout << max_count << std::endl;
}
