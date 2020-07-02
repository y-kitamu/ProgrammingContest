#include <bits/stdc++.h>


int main() {
    int x, y;
    std::cin >> x >> y;

    while (x % y != 0) {
        int new_y = x % y;
        x = y;
        y = new_y;
    }
    std::cout << y << std::endl;
}
