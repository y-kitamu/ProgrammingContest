#include <bits/stdc++.h>


int main() {
    long long int L;
    std::cin >> L;

    std::vector<bool> check(11, true);
    long long int deno = 1;
    for (int i = 1; i <= 11; i++) {
        deno *= (L - i);
        for (int j = 0; j < 11; j++) {
            if (check[j] == true && deno % (j + 1) == 0) {
                deno /= (j + 1);
                check[j] = false;
            }
        }
    }
    std::cout << deno << std::endl;
}
