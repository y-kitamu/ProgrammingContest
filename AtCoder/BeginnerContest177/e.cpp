#include <bits/stdc++.h>


int main() {
    int N;
    std::cin >> N;
    std::map<int, int> map;

    for (int i = 0; i < N; i++) {
        int val;
        std::cin >> val;
        for (int j = 2; j < std::sqrt(val) + 1; j++) {
            if (val % j == 0) {
                if (map.find(j) == map.end()) {
                    map[j] = 1;
                } else {
                    map[j]++;
                }
            }
            while (val % j == 0) {
                val /= j;
            }
        }
        if (val > 1) {
            if (map.find(val) == map.end()) {
                map[val] = 1;
            } else {
                map[val]++;
            }
        }
    }

    bool is_pc = true;
    bool is_sc =  true;
    for (auto pair : map) {
        if (pair.second > 1) {
            is_pc = false;
        }
        if (pair.second == N) {
            is_sc = false;
        }
    }
    if (is_pc) {
        std::cout << "pairwise coprime" << std::endl;
    } else if (is_sc) {
        std::cout << "setwise coprime" << std::endl;
    } else {
        std::cout << "not coprime" << std::endl;
    }
}
