#include <bits/stdc++.h>


int main() {
    int N;
    std::cin >> N;

    bool flag = true;
    for (int i = 0; i < N; i++) {
        int A;
        std::cin >> A;
        if (A % 2 == 0) {
            flag &= ((A % 3 == 0) || (A % 5 == 0));
        }
    }

    if (flag) {
        std::cout << "APPROVED" << std::endl;
    } else {
        std::cout << "DENIED" << std::endl;
    }
}
