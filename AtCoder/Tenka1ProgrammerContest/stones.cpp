#include <iostream>
#include <string>


int main() {
    int N;
    std::cin >> N;

    std::string S;
    std::cin >> S;

    int reverse_cnt = 0;
    for (int i = 0; i < N; i++) {
        if (S[i] == '.') reverse_cnt++;
    }

    int min_reverse_cnt = reverse_cnt;
    for (int i = 0; i < N; i++) {
        if (S[i] == '.') {
            reverse_cnt--;
            if (reverse_cnt < min_reverse_cnt) {
                min_reverse_cnt = reverse_cnt;
            }
        }
        if (S[i] == '#') {
            reverse_cnt++;
        }
    }
    std::cout << min_reverse_cnt << std::endl;
}
