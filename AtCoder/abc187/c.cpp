#include <bits/stdc++.h>


int main() {
    int N;
    std::cin >> N;

    std::set<std::string> aset, bset;
    std::string output = "satisfiable";
    for (int i = 0; i < N; i++) {
        std::string str;
        std::cin >> str;
        if (str[0] == '!') {
            str = str.substr(1);
            aset.insert(str);
            if (bset.find(str) != bset.end()) {
                output = str;
            }
        } else {
            bset.insert(str);
            if (aset.find(str) != aset.end()) {
                output = str;
            }
        }
    }

    std::cout << output << std::endl;
}
