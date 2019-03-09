#include <iostream>


int main() {
    int H, W, h, w;
    std::cin >> H >> W >> h >> w;

    std::cout << H * W - (H * w + h * W - h * w) << std::endl;
}
