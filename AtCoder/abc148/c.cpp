#include <bits/stdc++.h>


long long int gcd(long long int a, long long int b) {
    while (b > 0) {
        auto tmp = b;
        b = a % b;
        a = tmp;
    }
    return a;
}


int main() {
    long long int A, B;
    std::cin >> A >> B;
    long long int g = gcd(A, B);
    std::cout << A * B / g << std::endl;
}
