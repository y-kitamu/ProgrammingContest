#include <bits/stdc++.h>


bool check_prime(int val) {
    for (int i = 2; i <= std::sqrt(val); i++) {
        if (val % i == 0) {
            return false;
        }
    }
    return true;
}


int main() {
    int N;
    std::cin >> N;
    int count = 0;
    for (int i = 0; i < N; i++) {
        int val;
        std::cin >> val;
        if (check_prime(val)) {
            count++;
        }
    }
    std::cout << count << std::endl;
}
