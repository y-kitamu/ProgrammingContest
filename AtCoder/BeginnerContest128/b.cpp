#include <bits/stdc++.h>


int main() {
    int N;
    std::cin >> N;
    std::map<std::string, std::vector<std::pair<int, int>>> city_rests;

    for (int i = 0; i < N; i++) {
        std::string city;
        int point;
        std::cin >> city >> point;
        if (city_rests.find(city) == city_rests.end()) {
            city_rests[city] = std::vector<std::pair<int, int>>();
        }
        city_rests[city].emplace_back(std::make_pair(i, point));
    }

    for (auto city : city_rests) {
        std::sort(city.second.begin(), city.second.end(), [](std::pair<int, int> &lhs, std::pair<int, int> &rhs) { return lhs.second > rhs.second; });
        for (auto rest : city.second) {
            std::cout << rest.first + 1 << std::endl;
        }
    }
}
