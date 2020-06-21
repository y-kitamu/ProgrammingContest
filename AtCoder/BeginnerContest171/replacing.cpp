#include <bits/stdc++.h>


int main() {
    int N;
    std::cin >> N;

    std::map<long long int, long long int> A;
    for (int i = 0; i < N; i++) {
        int in;
        std::cin >> in;
        if (A.find(in) == A.end()) {
            A[in] = 0;
        }
        A[in]++;
    }
    int Q;
    std::cin >> Q;
    long long int sum = 0;
    for (auto && pair : A) {
        sum += pair.first * pair.second;
    }
    for (int i = 0; i < Q; i++) {
        int B, C;
        std::cin >> B >> C;
        if (A.find(C) == A.end()) {
            A[C] = 0;
        }
        if (A.find(B) != A.end()) {
            sum += (C - B) * A[B];
            A[C] += A[B];
            A.erase(B);
        }
        std::cout << sum << std::endl;
    }
}
