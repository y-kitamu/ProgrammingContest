#include <iostream>

int main() {
    int N;

    std::cin >> N;

    int H;
    int max_height = 0, count = 0;
    for (int i = 0; i < N; i++) {
        std::cin >> H;
        if (max_height <= H) {
            count++;
            max_height = H;
        }
    }
    std::cout << count << std::endl;
}
