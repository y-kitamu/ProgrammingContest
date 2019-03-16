#include <iostream>

int main() {
    int N;
    std::cin >> N;
    char c;

    long character[300] = {};

    long cnt = 1;

    for (int i = 0; i < N; i++) {
        std::cin >> c;

        character[c - 'a']++;
    }

    for (int i = 0; i < 100; i++) {
        cnt = (cnt * (character[i] + 1)) % (long)(10e9 + 7);
    }

    std::cout << cnt - 1 << std::endl;
}
