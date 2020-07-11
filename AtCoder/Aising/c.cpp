#include <bits/stdc++.h>

int main() {
    int N;
    std::cin >> N;

    std::vector<int> map(N, 0);
    int max = int(std::sqrt(N)) + 1;

    for (int x = 1; x < max; x++) {
        for (int y = x; y < max; y++) {
            for (int z = y; z < max; z++) {
                int val = x * x + y * y + z * z + x * y + y * z + z * x;
                if (val <= N) {
                    if (x == y && y == z) {
                        map[val - 1]++;
                    } else if (x == y || y == z) {
                        map[val - 1] += 3;
                    } else {
                        map[val - 1] += 6;
                    }
                }
            }
        }
    }
    for (int i = 0; i < N; i++) {
        std::cout << map[i] << std::endl;
    }
}
