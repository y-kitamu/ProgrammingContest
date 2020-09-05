#include <bits/stdc++.h>


int main() {
    int t;
    std::cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        std::cin >> n;
        std::map<char, int> map;
        for (int j = 0; j < n; j++) {
            std::string str;
            std::cin >> str;
            for (auto c : str) {
                if (map.find(c) == map.end()) {
                    map[c] = 0;
                }
                map[c]++;
            }
        }
        bool flag =true;
        for (auto pair : map) {
            if (pair.second % n != 0) {
                flag = false;
                break;
            }
        }
        if (flag) {
            std::cout << "YES" << std::endl;
        } else {
            std::cout << "NO" << std::endl;
        }
    }
}
