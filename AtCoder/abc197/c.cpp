#include <bits/stdc++.h>


int main() {
    int N;
    std::cin >> N;
    std::vector<unsigned int> A(N);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    unsigned int min = 1 << 30;
    for (int i = 0; i < (1 << N); i++) {
        unsigned int sum = 0;
        unsigned int ors = A[0];
        // std::cout << i << std::endl;
        for (int j = 1; j < N; j++) {  //
            if (((i >> j) & 1) == ((i >> (j - 1)) & 1)) {
                ors |= A[j];
            } else {
                // std::cout << j << " ";
                // std::cout << ors << " ";
                sum ^= ors;
                ors = A[j];
            }
        }
        // std::cout << N << std::endl;
        sum ^= ors;
        min = std::min(sum, min);
    }
    std::cout << min << std::endl;
}
