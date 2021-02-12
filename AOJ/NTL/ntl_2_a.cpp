#include <bits/stdc++.h>


int main() {
    std::string rawA, rawB;
    std::cin >> rawA >> rawB;

    int fa = 1, fb = 1;
    std::string A = rawA, B = rawB;
    if (A[0] == '-') {
        fa = -1;
        A.erase(0, 1);
    }
    if (B[0] == '-') {
        fb = -1;
        B.erase(0, 1);
    }
    // std::cout << A << " , " << B << std::endl;

    bool is_swap = A.size() < B.size();
    if (A.size() == B.size()) {
        for (int i = 0; i < A.size(); i++) {
            if (A[i] == B[i]) {
                continue;
            }
            is_swap = A[i] < B[i];
            break;
        }
    }

    if (is_swap) {
        std::swap(A, B);
        std::swap(fa, fb);
        std::swap(rawA, rawB);
    }

    int diff = (A.size() - B.size());
    for (int i = 0; i < diff; i++) {
        B = '0' + B;
    }

    int f = fa * fb;
    int next = 0;
    std::string s = "";
    // std::cout << A << std::endl;
    // std::cout << B << std::endl;
    for (int i = 1; i <= A.size(); i++) {
        int val = A[A.size() - i] - '0' + f * (B[B.size() - i] - '0') + next;
        if (val > 9) {
            next = 1;
            val -= 10;
        } else if (val < 0) {
            next = -1;
            val += 10;
        } else {
            next = 0;
        }
        s = std::to_string(val) + s;
    }
    if (next != 0) {
        s = "1" + s;
    }

    while (s.size() > 1 && s[0] == '0') {
        s.erase(0, 1);
    }

    if (s != "0" && fa < 0) {
        s = "-" + s;
    }

    std::cout << s << std::endl;
}
