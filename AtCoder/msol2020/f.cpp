#include <bits/stdc++.h>

struct Plane {
    long long int x, y;
    char u;
};




int main() {
    int N;
    std::cin >> N;

    std::vector<Plane> us, ds, ls, rs;
    for (int i = 0; i < N; i++) {
        int x, y;
        char u;
        std::cin >> x >> y >> u;
    }

    std::cout << "SAFE" << std::endl;
}
