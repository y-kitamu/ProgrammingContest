#include <bits/stdc++.h>


int main() {
    int N;
    std::cin >> N;
    std::vector<std::pair<std::string, int>> vec(N);
    for (int i = 0; i < N; i++) {
        std::cin >> vec[i].first >> vec[i].second;
    }

    std::sort(vec.begin(), vec.end(), [](auto& lhs, auto& rhs) { return lhs.second > rhs.second; });

    std::cout << vec[1].first << std::endl;
}
