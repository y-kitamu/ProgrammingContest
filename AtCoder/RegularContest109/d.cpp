#include <bits/stdc++.h>


int main() {
    int T;
    std::cin >> T;
    for (int i = 0; i < T; i++) {
        int ax, ay, bx, by, cx, cy;
        std::cin >> ax >> ay >> bx >> by >> cx >> cy;
        int max_x = std::max(std::max(ax, bx), cx);
        int max_y = std::max(std::max(ay, by), cy);
    }
}
