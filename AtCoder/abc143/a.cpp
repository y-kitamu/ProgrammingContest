#include <bits/stdc++.h>


int main() {
    int A, B;
    std::cin >> A >> B;
    int res = std::max(A - B * 2, 0);
    std::cout << res << std::endl;
}
