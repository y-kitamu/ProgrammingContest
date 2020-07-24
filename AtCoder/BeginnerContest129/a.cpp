#include <bits/stdc++.h>


int main() {
    int P, Q, R;
    std::cin >> P >> Q >> R;
    int mini = std::min(std::min(P + Q, Q + R), R + P);
    std::cout << mini << std::endl;
}
