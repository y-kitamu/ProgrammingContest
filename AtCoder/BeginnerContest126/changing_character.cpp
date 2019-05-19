#include <iostream>
#include <string>

int main() {
    int N, K;
    std::string S;
    std::cin >> N >> K;
    std::cin >> S;

    K = K - 1;
    if (S[K] == 'A') {
        S[K] = 'a';
    } else if (S[K] == 'B') {
        S[K] = 'b';
    } else if (S[K] == 'C') {
        S[K] = 'c';
    }

    std::cout << S << std::endl;
}
