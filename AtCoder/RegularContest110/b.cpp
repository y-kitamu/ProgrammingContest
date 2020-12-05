#include <bits/stdc++.h>


int main() {
    int N;
    std::cin >> N;
    std::string T;
    std::cin >> T;

    if (N == 1) {
        if (T[0] == '0') {
            std::cout << (long long int)1e10 << std::endl;
        } else {
            std::cout << (long long int)1e10 * 2 << std::endl;
        }
        return 0;
    }

    if (N == 2) {
        if (T[0] == '0' && T[1] == '0') {
            std::cout << 0 << std::endl;
        } else {
            if (T[0] == '0' && T[1] == '1') {
                std::cout << (long long int)1e10 - 1 << std::endl;
            } else {
                std::cout << (long long int)1e10 << std::endl;
            }
        }
        return 0;
    }

    int cnt0 = (int)(T[0] == '0') + (int)(T[1] == '0') + (int)(T[2] == '0');
    int cnt1 = (int)(T[0] == '1') + (int)(T[1] == '1') + (int)(T[2] == '1');
    if (cnt0 >= 2 || cnt1 == 3) {
        std::cout << 0 << std::endl;
        return 0;
    }

    bool flag = true;
    for (int i = 0; i < T.length() - 3; i++) {
        flag &= T[i] == T[i + 3];
    }
    if (!flag) {
        std::cout << 0 << std::endl;
        return 0;
    }

    int length = T.length();
    if (T[0] == '0')  {
        length += 2;
    }
    if (T[1] == '0') {
        length += 1;
    }
    long long int num_per_one = length / 3;
    if (length % 3 != 0) {
        num_per_one++;
    }
    std::cout << (long long int)1e10 - num_per_one + 1 << std::endl;
}
