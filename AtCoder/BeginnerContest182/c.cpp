#include <bits/stdc++.h>


int main() {
    std::string N;
    std::cin >> N;

    std::vector<int> cnt(3, 0);
    int sum = 0;
    for (auto c : N)  {
        int val = (c - '0') % 3;
        cnt[val]++;
        sum += val;
    }
    sum = sum % 3;

    if (sum == 0) {
        std::cout << 0 << std::endl;
        return 0;
    }
    if (N.length() > 1 && cnt[sum] > 0) {
        std::cout << 1 << std::endl;
        return 0;
    }
    if (N.length() > 2 && cnt[3 - sum] > 1) {
        std::cout << 2 << std::endl;
        return 0;
    }
    std::cout << -1 << std::endl;
}
