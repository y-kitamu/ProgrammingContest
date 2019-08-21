#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

int main() {
    int N;
    std::cin >> N;
    std::map<std::string, int> anagram;
    for (int i = 0; i < N; i++) {
        std::string str_in;
        std::cin >> str_in;
        std::sort(str_in.begin(), str_in.end(),
                  [](const auto &lhs, const auto &rhs){return int(lhs) < int(rhs);});
        if (anagram.find(str_in) == anagram.end()) {
            anagram[str_in] = 1;
        } else {
            anagram[str_in]++;
        }
    }

    long long count = 0;
    for (auto && item : anagram) {
        long long num = item.second;
        count += num * (num - 1) / 2;
    }

    std::cout << count << std::endl;
}
