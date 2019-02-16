#include <iostream>
#include <algorithm>
#include <vector>


int main() {
    int N;
    std::cin >> N;

    std::vector<int> monster(N);

    for (int i = 0; i < N; i++) {
        std::cin >> monster[i];
    }

    int cnt = 0;

    while (cnt < N - 1) {
        cnt = 0;
        int min_val = 1e9;
        int min_idx = 0;
        for (int i = 0; i < N; i++) {
            if (min_val > monster[i] && monster[i] > 0) {
                min_val = monster[i];
                min_idx = i;
            } 
        }

        for (int i = 0; i < N; i++) {
            if (i == min_idx) continue;
            if (monster[i] - monster[min_idx] > 0) {
                monster[i] = monster[i] % monster[min_idx];
            } else {
                monster[i] = 0;
            }
            if (monster[i] == 0) {
                cnt++;
            }
        }
    }

    for (auto && val : monster) {
        if (val != 0) {
            std::cout << val << std::endl;
            break;
        }
    }
}
