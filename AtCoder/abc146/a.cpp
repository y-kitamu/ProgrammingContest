#include <bits/stdc++.h>


int main() {
    std::string S;
    std::cin >> S;
    if ("SUN" == S) {
        std::cout << 7 << std::endl;
    } else if ("MON" == S) {
        std::cout << 6 << std::endl;
    } else if ("TUE" == S) {
        std::cout << 5 << std::endl;
    } else if ("WED" == S) {
        std::cout << 4 << std::endl;
    } else if ("THU" == S) {
        std::cout << 3 << std::endl;
    } else if ("FRI" == S) {
        std::cout << 2 << std::endl;
    } else if ("SAT" == S) {
        std::cout << 1 << std::endl;
    }
}
