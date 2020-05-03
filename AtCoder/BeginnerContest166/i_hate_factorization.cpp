#include <iostream>

bool pow5(int i, int X) {
    int val = X / i - i * i * i * i;
    if (val % 5 != 0) {
        return false;
    }
    val /= 5;

    auto judge = [&i] (int b, int val) {
        if (b * (b + i) * (b * b + b * i + i * i) == -val) {
            std::cout << b + i << " " << b << std::endl;
            return true;
        }
        return false;
    };

    for (int j = 1; j <= std::abs(val); j++) {
        if (val % j == 0) {
            if (judge(j, val / j) || judge(-j, -val / j)) {
                return true;
            }
        }
    }
    return false;
}


int main() {
    int X;
    std::cin >> X;

    for (long long int i = 1;; i++) {
        long long int val = i * i * i * i * i;
        if (val == X) {
            std::cout << i << " " << 0 << std::endl;
            return 0;
        }
        if (val > X) {
            break;
        }
    }

    for (int i = 1; i <= X; i++) {
        if (X % i != 0) {
            continue;
        }
        if (pow5(i, X) || pow5(-i, X)) {
            break;
        }
    }
}
