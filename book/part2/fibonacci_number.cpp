#include <iostream>


int main() {
    int n0 = 1, n1 = 1;

    int n;
    std::cin >> n;

    for (int i = 1; i < n; i++) {
        int tmp = n1;
        n1 = n0 + n1;
        n0 = tmp;
    }
    std::cout << n1 << std::endl;
}
