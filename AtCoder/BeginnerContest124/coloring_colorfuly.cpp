#include <iostream>
#include <string>


int main() {
    std::string S;
    std::cin >> S;

    int size = S.length();
    int count = 0;
    for (int i = 0; i < size; i++) {
        char c = i % 2 == 0 ? '0' : '1';
        if (S[i] != c) {
            count++;
        }
    }

    count = std::min(size - count, count);
    std::cout << count << std::endl;
}
