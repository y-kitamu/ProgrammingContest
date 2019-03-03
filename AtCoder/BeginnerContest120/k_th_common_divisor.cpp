#include <iostream>

int main() {
    int A, B, K;

    std::cin >> A >> B >> K;

    int count = 0, num = std::min(A, B) + 1;
    while (count < K) {
        num--;
        if (A % num == 0 && B % num == 0) count++;
    }
    std::cout << num << std::endl;
}
