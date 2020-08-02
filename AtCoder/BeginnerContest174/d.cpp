#include <bits/stdc++.h>


int main() {
    int N;
    std::cin >> N;
    std::string cs;
    std::cin >> cs;
    int red = 0;
    for (int i = 0; i < N; i++) {
        if (cs[i] == 'R') {
            red++;
        }
    }
    int swap = 0;
    for (int i = 0; i < red; i++) {
        if (cs[i] == 'W') {
            swap++;
        }
    }
    std::cout << swap << std::endl;
}
