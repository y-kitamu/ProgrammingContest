#include <bits/stdc++.h>

int main() {
    int N;
    std::cin >> N;

    std::map<std::string, int> map;
    map["AC"] = 0;
    map["WA"] = 0;
    map["TLE"] = 0;
    map["RE"] = 0;

    for (int i = 0; i < N; i++) {
        std::string str;
        std::cin >> str;
        map[str]++;
    }

    std::cout << "AC x " << map["AC"] << std::endl;
    std::cout << "WA x " << map["WA"] << std::endl;
    std::cout << "TLE x " << map["TLE"] << std::endl;
    std::cout << "RE x " << map["RE"] << std::endl;
}
