#include <bits/stdc++.h>


int main() {
    int n;
    std::cin >> n;
    int num = n;

    int sqrt = std::sqrt(n) + 1;
    int deno = 1, nume = 1;
    for (int i = 2; i <= sqrt; i++) {
        if (n % i == 0) {
            deno *= (i - 1);
            nume *= i;
        }
        while (n % i == 0) {
            n /= i;
        }
    }
    if (n > 1) {
        deno *= (n - 1);
        nume *= n;
    }
    std::cout << num / nume * deno << std::endl;
}
