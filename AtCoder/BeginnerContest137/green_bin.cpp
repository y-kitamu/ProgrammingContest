#include <iostream>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <vector>
#include <cmath>


int main() {
    int N;
    std::cin >> N;

    auto create_map = [](std::string str) {
        double num = 0;
        for (auto && c : std::set<char>(str.begin(), str.end())) {
            num += std::count(str.begin(), str.end(), c) * std::pow(10.0, (int)(c - 'a'));
        }
        return num;
    };

    std::vector<double> analogy_list;
    for (int i = 0; i < N; i++) {
        std::string str;
        std::cin >> str;
        analogy_list.emplace_back(create_map(str));
    }

    std::vector<bool> flag(N, false);
    long long int count = 0;
    for (int i = 0; i < N; i++) {
        if (flag[i]) {
            continue;
        }
        flag[i] = true;
        long long int dup = 1;
        for (int j = i + 1; j < N; j++) {
            if (std::abs(analogy_list[i] - analogy_list[j]) < 1.0e-5) {
                flag[j] = true;
                dup++;
            }
        }
        count += dup * (dup - 1) / 2;
    }
    
    std::cout << count << std::endl;
}
