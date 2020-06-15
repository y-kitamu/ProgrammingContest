#include <bits/stdc++.h>

int main() {
    long long int A;
    std::string B;
    std::cin >> A >> B;

    B.erase(1, 1);
    long long int ib = atoi(B.c_str());
    long long int FACTOR = 100;

    std::cout << A * ib / FACTOR << std::endl;
}
