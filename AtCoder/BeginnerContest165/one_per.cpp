#include <iostream>


int main() {
    long long int X;
    std::cin >> X;
    long long int sum = 100;
    double ratio = 1.01;

    int idx = 0;
    while (sum < X) {
        sum = sum * ratio;
        idx++;
    }

    std::cout << idx << std::endl;
}
