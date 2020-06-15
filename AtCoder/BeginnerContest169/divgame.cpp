#include <bits/stdc++.h>


int main() {
    long long int N;
    std::cin >> N;

    std::map<int, int> prime_counts;
    long long int max = sqrt(N);
    for (int i = 2; i <= max; i++) {
        while (N % i == 0) {
            if (prime_counts.find(i) == prime_counts.end()) {
                prime_counts[i] = 0;
            }
            prime_counts[i]++;
            N /= i;
        }
        max = sqrt(N);
    }


    int count = 0;
    for (auto && pair: prime_counts) {
        int pc = pair.second;
        for (int i = 2;; i++) {
            count++;
            pc -= i;
            if (pc <= 0) {
                break;
            }
        }
    }
    if (N != 1) {
        count++;
    }

    std::cout << count << std::endl;
}
