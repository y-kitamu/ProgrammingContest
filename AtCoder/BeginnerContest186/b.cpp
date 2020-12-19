#include <bits/stdc++.h>


int main() {
    int H, W;
    std::cin >> H >> W;

    std::vector<std::vector<int>> nums(H, std::vector<int>(W));
    int min = 100;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            std::cin >> nums[i][j];
            min = std::min(min, nums[i][j]);
        }
    }

    int sum = 0;
    for (int i = 0; i < H; i++){
        for (int j = 0; j < W; j++) {
            sum += nums[i][j] - min;
        }
    }
    std::cout << sum << std::endl;
}
