#include <iostream>
#include <map>
#include <string>


int main() {
    int n;
    std::cin >> n;
    std::map<std::string, bool> T;

    for (int i = 0; i < n; i++) {
        std::string str, com;
        std::cin >> com >> str;
        if (com == "insert") T[str] = true;
        else {
            if (T[str]) std::cout << "yes" << std::endl;
            else std::cout << "no" << std::endl;
        }
    }

    return 0;
}
