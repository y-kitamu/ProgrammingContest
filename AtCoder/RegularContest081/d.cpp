#include <bits/stdc++.h>


int main() {
    long long int MAX = 1000000007;
    int N;
    std::string S1, S2;
    std::cin >> N;
    std::cin >> S1 >> S2;

    long long int scale = 3;
    for (int i = 0; i < N; i++) {
        if (S1[i] != S2[i]) {
            if (i == 0 || S1[i - 1] == S2[i - 1]) {
                scale = (scale * 2) % MAX;
            } else {
                scale = (scale * 3) % MAX;
            }
            i++;
        } else {
            if (i > 0 && S1[i - 1] == S2[i - 1]) {
                scale = (scale * 2) % MAX;
            }
        }
    }
    std::cout << scale << std::endl;
}
