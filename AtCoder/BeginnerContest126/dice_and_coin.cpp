#include <iostream>
#include <iomanip>
#include <cmath>

int main() {
    int N, K;

    std::cin >> N >> K;

    int i = K - 1;
    int num = 1;
    double p = 0.0;
    if (N >= K) {
        p += 1.0 / N * (N - i);
        
    }
    while (i > 1) {
        if (i / 2 > N) {
            num++;
            i = i / 2;
            continue;
        }
        int tmp_i = i / 2;
        p += std::pow(0.5, num) * (std::min(i, N) - tmp_i) / N;
        i = tmp_i;
        num++;
    }
    if (i == 1 && K != 1) {
        p += std::pow(0.5, num) * 1.0 / N;
    }
    std::cout << std::setprecision(11) <<  p << std::endl;
}
