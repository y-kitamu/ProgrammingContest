#include <bits/stdc++.h>


int main() {
    long long int A, B;
    std::cin >> A >> B;
    auto disc = double((A - B) * 100) / A;
    std::cout << std::fixed << std::setprecision(5) << disc << std::endl;
}
