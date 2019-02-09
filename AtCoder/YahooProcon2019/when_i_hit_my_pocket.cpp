#include <iostream>


int main() {
    long K, A, B;

    std::cin >> K >> A >> B;

    long biscket = 1;
    if (A + 2 < B) {
        while (K > 0 && biscket < A) {
            biscket++;
            K--;
        }
        biscket += K / 2 * (B - A)  + K % 2;
    } else {
        biscket = K + 1;
    }

    std::cout << biscket << std::endl;
}
