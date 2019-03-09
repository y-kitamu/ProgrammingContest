#include <iostream>


int main() {
    long A, B;

    std::cin >> A >>  B;
    long val = 0;
    long factor = 1;

    auto calc_one_num = [&factor] (long N) {
        long div_n = N / (factor * 2);
        long res_n = N % (factor * 2);
        long num = div_n * factor;
        if (res_n < factor) return num;
        return num + res_n - factor;
    };

    while (B >= factor) {
        long a = calc_one_num(A);
        long b = calc_one_num(B + 1);
        
        if (std::abs(b - a) % 2) {
            val += factor;
        }
        factor *= 2;
    }
    std::cout << val << std::endl;
}
