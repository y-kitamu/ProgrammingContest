#include <bits/stdc++.h>


int main() {
    int N, M;
    std::cin >> N >> M;

    std::vector<int> A(N);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::set<int> exc;
    for (int i = 0; i <= N; i++) {
        exc.insert(i);
    }

    std::multiset<int> inc;
    for (int i = 0; i < M; i++) {
        inc.insert(A[i]);
        if (exc.find(A[i]) != exc.end()) {
            exc.erase(A[i]);
        }
    }

    int min = *exc.begin();
    for (int i = 0; i < N - M; i++) {
        auto itr = inc.find(A[i]);
        inc.erase(itr);
        if (inc.find(A[i]) == inc.end()) {
            exc.insert(A[i]);
        }

        inc.insert(A[i + M]);
        if (exc.find(A[i + M]) != exc.end()) {
            exc.erase(A[i + M]);
        }
        min = std::min(min, *exc.begin());
    }
    std::cout << min << std::endl;
}
