#include <bits/stdc++.h>


long long int step(long long int Y, long long int X, std::map<long long int, long long int>& map) {
    if (Y <= X) {
        return X - Y;
    }
    if (map.find(Y) != map.end()) {
        return map[Y];
    }
    long long int res = Y - X;
    if (Y % 2 == 0) {
        res = std::min(step(Y / 2, X, map) + 1, res);
    } else {
        res = std::min(std::min(step((Y + 1) / 2, X, map), step((Y - 1) / 2, X, map)) + 2, res);
    }
    map[Y] = res;
    return res;
}

int main() {
    long long int X, Y;
    std::cin >> X >> Y;

    if (X >= Y) {
        std::cout << X - Y << std::endl;
        return 0;
    }

    std::map<long long int, long long int> map;
    std::cout << step(Y, X, map) << std::endl;;
}
